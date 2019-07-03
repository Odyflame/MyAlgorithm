#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int visited[1000001];
queue<int> qu;

int bfs(int x, int y) {
	qu.push(x);
	visited[x] = 0;
	while (!qu.empty()) {
		x = qu.front();
		qu.pop();

		if (x == y) break;

		if (x > 0 && visited[x - 1] == -1) {
			qu.push(x - 1);
			visited[x - 1] = visited[x] + 1;
		}if (x < y && visited[x + 1] == -1) {
			qu.push(x + 1);
			visited[x + 1] = visited[x] + 1;
		}if (x < y && visited[x*2] == -1) {
			qu.push(x*2);
			visited[x*2] = visited[x];
		}
	}
	return visited[x];
}

int main() {
	memset(visited, -1, sizeof(visited));
	int n, m;
	cin >> n >> m;
	cout << bfs(n, m);
}