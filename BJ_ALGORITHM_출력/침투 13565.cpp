#include <iostream>
#include <string>

using namespace std;

int arr[1002][1002], Count=0;
int X,Y;
int cache[1001][1001];
bool check = false;

void percolates(int x, int y) {
	
	if (x == X-1) check = true;
	
	cache[x][y] = 1;

	if (x > 0 && cache[x - 1][y] != 1 && cache[x - 1][y] != -1) percolates(x - 1, y);
	if (x < X && cache[x+1][y] != 1 && cache[x + 1][y] != -1) percolates(x + 1, y);
	if (y < Y && cache[x][y + 1] != 1 && cache[x][y + 1] != -1) percolates(x, y + 1);
	if (y > 0 && cache[x][y - 1] != 1 && cache[x][y - 1] != -1) percolates(x, y - 1);

}

int main() {

	cin >> X >> Y;
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			scanf("%1d", &arr[i][j]);
			cache[i][j] = arr[i][j];
		}
	}

	for (int j = 0; j < Y; j++) {
		if (arr[0][j] == 0) {
			percolates(0, j);
			if (check) break;
		}
	}
	
	if (check) cout << "YES";
	else cout << "NO";

}