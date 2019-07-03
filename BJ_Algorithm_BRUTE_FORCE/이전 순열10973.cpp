/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	
	cin >> n;
	vector<int> v(n+1);
	
	for (int i = 0; i < n; i++)	cin>>v[i];

	if (!prev_permutation(v.begin(), v.end()))	cout << -1;
	else for (auto ele : v)	cout << ele << " ";

	return 0;
}