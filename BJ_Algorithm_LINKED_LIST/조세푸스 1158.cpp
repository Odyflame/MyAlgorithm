/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> linked_list;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) linked_list.push_back(i + 1);

	vector<long long>::iterator iter = linked_list.begin();
	cout << "<";
	if (n == 1) cout << linked_list.front() << ">";
	else {
		for(int j=0;j<n;j++){

			if (iter == linked_list.end()) iter = linked_list.begin();

			for (int i = 0; i < m - 1; i++) {
				iter++;
				if (iter == linked_list.end()) iter = linked_list.begin();
			}
			
			cout << *iter;
			iter = linked_list.erase(iter);
			
			if (j != n - 1) cout << ", ";
		}
		cout << ">";
	}
	
}
