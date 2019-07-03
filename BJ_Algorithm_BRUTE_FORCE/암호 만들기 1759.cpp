/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> ans;

void dfs(int start, int depth, int mo, int ja) {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	char a;

	for (int i = 0; i < m; i++) {
		cin >> a;
		arr.push_back(a);
	}
	
	sort(arr.begin(), arr.end());
	
	dfs(0, 0, 0, 0);
}