#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

int n, m, arr[100][100], visited[100][100], cnt=1;
queue<pair<int, int>> vec;

#define inside(x,y) ((x >= 0) && (y >= 0) && (x < n) && (y < m))

int bfs(int x, int y) {
	
	visited[x][y] = 1;
	vec.push(pair<int, int>(x, y));

	while (!vec.empty()) {
		x = vec.front().first;
		y = vec.front().second;
		vec.pop();
		
		if (x == n - 1 && y == m - 1) break;

		if (inside(x + 1,y) && arr[x + 1][y] == 1 && visited[x + 1][y]==-1) {
			visited[x + 1][y] = visited[x][y] + 1;
			vec.push(pair<int, int>(x + 1, y));
		}if (inside(x,y + 1) && arr[x][y + 1] == 1 && visited[x ][y + 1] == -1) {
			visited[x][y + 1] = visited[x][y] + 1;
			vec.push(pair<int, int>(x, y + 1));
		}if (inside(x - 1,y) && arr[x - 1][y] == 1 && visited[x - 1][y] == -1) {
			visited[x - 1][y] = visited[x][y] + 1;
			vec.push(pair<int, int>(x - 1, y));
		}if (inside(x,y - 1) && arr[x][y - 1] == 1 && visited[x][y - 1] == -1) {
			visited[x][y - 1] = visited[x][y] + 1;
			vec.push(pair<int, int>(x, y - 1));
		}
	}

	return visited[x][y];
}

int main() {
	memset(visited, -1, sizeof(visited));
	memset(arr, -1, sizeof(arr));
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 0) visited[i][j] = 0;
		}
	}
	if (arr[0][0] == 0) cout << 0;
	else cout << bfs(0, 0);
}