#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

queue<pair<int,int>> qu;
int visited[3001][20001], n, Copy = 0;

inline int bfs(int x) {
	qu.push({x,0});
	visited[x][0] = 0;
	
	while (!qu.empty()) {
		x = qu.front().first;
		Copy = qu.front().second;
		qu.pop();

		if (x == n) break;
		if (x > 1 && visited[x - 1][Copy] == -1) {//1제거
			qu.push({ x - 1, Copy});
			visited[x - 1][Copy] = visited[x][Copy] + 1;
		}if (x < n && visited[x+Copy][Copy] == -1) {//붙여넣기
			qu.push({ x+Copy, Copy });
			visited[x+Copy][Copy] = visited[x][Copy] + 1;
		}if (x < n && visited[x][x] == -1) {//복사
			qu.push({ x, x });
			visited[x][x] = visited[x][Copy] + 1;
		}

	}
	return visited[x][Copy];
}

int main() {
	cin >> n;
	memset(visited, -1, sizeof(visited));
	cout << bfs(1);
}