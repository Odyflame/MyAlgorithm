/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)	v[i] = i+1;
	do {
		for (auto ele : v) {
			cout << ele << " ";
		}cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}