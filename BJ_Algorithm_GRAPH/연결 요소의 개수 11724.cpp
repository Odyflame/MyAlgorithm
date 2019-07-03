#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, Count=0, check=0
;
vector<int> graph[1002];
int arr[1002][1002];
bool visited[1002];

void dfs(int start, int depth) {

	visited[start] = true;

	for (int i = 0; i < (int)graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visited[next] && arr[start][next] == 1) {
			dfs(next, depth + 1);
			check++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	if (m == 0) cout << n;
	else {
		int from, to;
		for (int i = 0; i < m; i++) {
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
			arr[from][to] = arr[to][from] = 1;
		}

		memset(visited, false, sizeof(visited));

		for (int i = 1; i <= n; i++) {
			
			if (!graph[i].empty()) {
				dfs(i, 0);
				if (check > 0) Count++;
				check = 0;
			}
			else Count++;
		}

		cout << Count;
	}
}