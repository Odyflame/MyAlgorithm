#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[50][50];
vector<int> vec;
int visited[50][50];
int cnt = 0;
int w, h;

int search(int x, int y) {
	if (x < 0 || y < 0 || x >= h || y >= w || visited[x][y] == 0) return 0;
	if (visited[x][y] == 1) return 1;

	visited[x][y] = 1;

	cnt++;

	if (x >= 0 && y >= 0 && x < h && y < w) search(x, y - 1) + search(x, y + 1) + search(x + 1, y) + search(x - 1, y)
		+search(x+1,y+1)+search(x+1,y-1)+search(x-1,y+1)+search(x-1,y-1);

	return cnt;
}

int main() {

	cin >> w >> h;
	while (w != 0 && h != 0) {
		memset(visited, -1, sizeof(visited));
		memset(arr, -1, sizeof(arr));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%1d", &arr[i][j]);
				if (arr[i][j] == 0) visited[i][j] = 0;
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1 && visited[i][j] == -1) {
					vec.push_back(search(i, j)); cnt = 0;
				}
			}
		}

		cout << vec.size() << '\n';
		vec.clear();
		cin >> w >> h;
	}
}