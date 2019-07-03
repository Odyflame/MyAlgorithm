#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

#define inside(x,y) ((x >= 0) && (y >= 0) && (x < n) && (y < m))

int arr[1001][1001], n, m, Minus = 0, Plus = 0, ans=0;
int visited[1001][1001], cnt=0, Max=0;

queue<pair<int,int>>qu;

int bfs(int x, int y) {
	
	bool check = false;

	while (!qu.empty()) {
		x = qu.front().first;
		y = qu.front().second;

		qu.pop();
		check = false;

		if (inside(x + 1, y) && arr[x + 1][y] == 0 && visited[x + 1][y] == 0) {
			visited[x + 1][y] = visited[x][y] + 1;
			arr[x + 1][y] = 1;
			qu.push(pair<int, int>(x + 1, y));
			
			Max = (Max > visited[x + 1][y]) ? Max : visited[x + 1][y];
		}if (inside(x, y + 1) && arr[x][y + 1] == 0 && visited[x][y + 1] == 0) {
			visited[x][y + 1] = visited[x][y] + 1;
			arr[x][y + 1] = 1;
			qu.push(pair<int, int>(x, y + 1));
			
			Max = (Max > visited[x][y + 1]) ? Max : visited[x][y + 1];
		}if (inside(x - 1, y) && arr[x - 1][y] == 0 && visited[x - 1][y] == 0) {
			visited[x - 1][y] = visited[x][y] + 1;
			arr[x - 1][y] = 1;
			qu.push(pair<int, int>(x - 1, y));
			
			Max = (Max > visited[x - 1][y]) ? Max : visited[x - 1][y];
		}if (inside(x, y - 1) && arr[x][y - 1] == 0 && visited[x][y - 1] == 0) {
			visited[x][y - 1] = visited[x][y] + 1;
			arr[x][y -1] = 1;
			qu.push(pair<int, int>(x, y - 1));
			
			Max = (Max > visited[x][y - 1]) ? Max : visited[x][y - 1];
		}
	}

	return visited[x][y];
}

int main() {

	memset(visited, 0, sizeof(visited));

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) Minus++;
			if (arr[i][j] == 1) { Plus++; qu.push({ i,j }); }
		}
	}

	if ((n*m - Minus) == Plus) cout << 0;
	else {
		int xpos = qu.front().first;
		int ypos = qu.front().second;
		
		try {
			ans= bfs(xpos, ypos);
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (arr[i][j] == 0) throw - 1;
				}
			}
			cout << ans;

		}
		catch (int excep) {
			cout << excep;
		}
	}

}