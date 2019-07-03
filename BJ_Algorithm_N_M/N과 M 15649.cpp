/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
bool arr2[8];

void dfs(int depth) {
	
	if (depth == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		if (!arr2[i]) {
			arr2[i] = true;
			arr[depth] = i+1;
			dfs(depth + 1);
			arr2[i] = false;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) arr.push_back(i + 1);
	dfs(0);
}