#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
int arr[25][25];
vector<int> vec;
int visited[25][25];
int cnt = 0;

int search(int x,int y) {
	if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y] == 0) return 0;
	if (visited[x][y] == 1) return 1;

	visited[x][y] = 1;
	
	cnt++;
	
	if (x >= 0 && y >= 0 && x < n && y < n) search(x, y - 1) + search(x, y + 1) + search(x + 1, y) + search(x-1,y) ;

	return cnt;
}


int main() {

	cin >> n;

	memset(visited, -1, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 0) visited[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j]==-1) { 
				vec.push_back(search(i, j)); cnt = 0;
			}
		}
	}

	cout << vec.size() << '\n';
	sort(vec.begin(), vec.end());
	for (auto ele : vec) cout << ele << '\n';
}