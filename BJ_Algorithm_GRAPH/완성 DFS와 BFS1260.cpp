#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, v;

int arr[1002][1002];
vector<int> graph[1002];
queue<int> qu;
bool visited[1002];

void dfs(int start, int depth) {
	
	cout << start << " ";

	visited[start] = true;
	
	for (int i = 0; i < (int)graph[start].size(); i++) {
		int next = graph[start][i];
		if (visited[next]||arr[start][next]!=1) continue;
		dfs(next, depth + 1);
	}
}

void bfs(int start) {

	visited[start] = true;
	qu.push(start);

	while (!qu.empty()) {
		start = qu.front();
		qu.pop();
		cout << start << " ";

		for (int i = 0; i <graph[start].size(); i++) {
			if (!visited[graph[start][i]]) {
				visited[graph[start][i]] = true;
				qu.push(graph[start][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> v;
	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		arr[from][to] = arr[to][from] = 1;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 0; i < n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v, 0);
	cout<<endl;
	memset(visited, false, sizeof(visited));
	bfs(v);
}