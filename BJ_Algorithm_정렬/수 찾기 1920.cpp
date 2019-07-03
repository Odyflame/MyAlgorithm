/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t, a, b, c;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a;
	vector<int> vec1;
	vector<int> vec2;
	for (int j = 0; j < a; j++) {
		cin >> c;
		vec1.push_back(c);
	}

	cin >> b;
	for (int j = 0; j < b; j++) {
		cin >> c;
		if (find(vec1.begin(), vec1.end(), c) != vec1.end()) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}