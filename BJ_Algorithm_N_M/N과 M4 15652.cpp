/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[9];

vector<int> ans;

int visited[9];

void dfs(int start, int depth) {

	if (depth == m) {
		for (auto ele : ans) cout << ele << " ";
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++) {
		ans.push_back(arr[i]);
		dfs(i, depth + 1);
		ans.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) arr[i] = i;

	dfs(1, 0);
}