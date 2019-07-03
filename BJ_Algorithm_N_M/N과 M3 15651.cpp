/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[9];
bool arr2[9];

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {

			arr[depth]=i + 1;
			dfs(depth + 1);	
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	
	dfs(0);
}