/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a;
vector<int> arr;
vector<int> arr3;
bool arr2[8];

void dfs(int start, int depth) {

	if (depth == m) {
		for (int i = 0; i < m; i++) cout << arr3[i] << " ";
		cout << '\n';
	}

	for (int i = start; i < n; i++) {
		
		if (!arr2[i]) {
			arr2[i] = true;
			arr3.push_back(arr[i]);
			dfs(i+1, depth + 1);
			arr3.pop_back();
			arr2[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) { cin >> a; arr.push_back(a); }
	sort(arr.begin(), arr.end());
	dfs(0,0);
}