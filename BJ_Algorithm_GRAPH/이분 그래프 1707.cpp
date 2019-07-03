#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int k, v, e;

vector<int> arr2[20003];

int colors[20003];
int from, to;

void dfs(int start, int color) {
	colors[start] = color;

	for (int i = 0; i < arr2[start].size(); i++) {
		int next = arr2[start][i];
		if (!colors[next]) dfs(next, 3 - color);
	}
}

bool isBipartiteGraph() {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < arr2[i].size(); j++) {
			int next = arr2[i][j];
			if (colors[i] == colors[next]) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;

	for (int b = 0; b < k; b++) {
		cin >> v >> e;

		//색깔과 값이 저장된 벡터 초기화
		memset(colors, 0, sizeof(colors));
		for (int i = 1; i <= v; i++) arr2[i].clear();

		for (int i = 0; i < e; i++) {
			cin >> from >> to;

			arr2[from].push_back(to);
			arr2[to].push_back(from);

		}

		for (int i = 1; i <= v; i++) {
			if (!colors[i]) dfs(i, 1);
		}

		if (isBipartiteGraph()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}