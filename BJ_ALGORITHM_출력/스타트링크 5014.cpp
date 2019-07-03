#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int f, s, g, u, d, visited[1000001];
queue<int> qu;

void bfs() {
	while (!qu.empty()) {
		s = qu.front();
		qu.pop();

		if (s == g) break;

		if (visited[s + u] == -1 && s + u <= f) {
			qu.push(s + u); visited[s + u] = visited[s] + 1;
		}
		if (visited[s - d] == -1 && s - d > 0) {
			qu.push(s - d); visited[s - d] = visited[s] + 1;
		}
	}
}

int main() {
	memset(visited, -1, sizeof(visited));
	cin >> f >> s >> g >> u >> d;
	visited[s] = 0;
	qu.push(s);
	
	bfs();

	if (visited[g]==-1) cout << "use the stairs";
	else cout << visited[g];
}

