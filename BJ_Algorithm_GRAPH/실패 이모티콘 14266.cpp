#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

queue<int> qu;
int visited[1001], n, Max=2035, Copy=1;
int bfs(int x) {
	qu.push(x);
	visited[x] = 0;
	
	while (!qu.empty()) {
		x = qu.front();
		qu.pop();
		if (x == n) break;
		if (x - 1 >= 0 && visited[x - 1] == -1 ) {
			qu.push(x - 1);
			visited[x - 1] = visited[x] + 1;
		}
		if (2 * x <= 2 * n && visited[2 * x] == -1) {
			qu.push(2 * x);
			visited[2 * x] = visited[x] + 2;
			Copy = x;
		}
	}

	return visited[n];
}

int main() {
	cin >> n;
	memset(visited, -1, sizeof(visited));
	cout<<bfs(1);
}