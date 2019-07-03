#include <iostream>
#include <string.h>
using namespace std;

int arr[51][51],t, m,n,k, x,y,sum;

int dfs(int startx, int starty) {
	arr[startx][starty] = 2;

	if (arr[startx][starty + 1] == 1) {
		dfs(startx, starty + 1);
	}if (arr[startx + 1][starty] == 1) {
		dfs(startx + 1, starty);
	}if (arr[startx - 1][starty] == 1) {
		dfs(startx - 1, starty);
	}if (arr[startx][starty - 1] == 1) {
		dfs(startx, starty - 1);
	}

	return 1;
}

int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		memset(arr, -1, sizeof(arr));
		sum = 0;
		cin >> m >> n >> k;
		
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			arr[y][x] = 1;
		}

		for (int j = 0; j < n; j++) {
			for (int c = 0; c < m; c++) {
				if (arr[j][c] == 1) {
					dfs(j, c);
					sum++;
				}
			}
		}
		cout << sum<<'\n';
	}
}