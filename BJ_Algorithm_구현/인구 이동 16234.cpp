#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <deque>
using namespace std;

int arr[51][51];
bool visited[51][51];
int n, l, r, a;
bool flag = false;
deque<pair<int, int>> deq;

void bfs(int a, int b) {
	deque<pair<int, int>> deq2;

	deq.push_back(make_pair(a, b));
	deq2.push_back(make_pair(a, b));
	visited[a][b] = true;
	int sum = arr[a][b];
	int index = 1;

	while (!deq.empty()) {

		int x = deq.front().first;
		int y = deq.front().second;

		deq.pop_front();

		if (!visited[x][y+1] && arr[x][y+1] > 0 && abs(arr[x][y] - arr[x][y + 1]) >= l && abs(arr[x][y] - arr[x][y + 1]) <= r) {
			sum += arr[x][y + 1];
			deq.push_back(make_pair(x, y + 1));
			deq2.push_back(make_pair(x, y + 1));
			visited[x][y + 1]=true;
			index++;
			flag = true;
		}
		if (!visited[x + 1][y] && arr[x + 1][y] > 0 && abs(arr[x][y] - arr[x+1][y]) >= l && abs(arr[x][y] - arr[x+1][y]) <= r) {
			sum += arr[x + 1][y];
			deq.push_back(make_pair(x + 1, y));
			deq2.push_back(make_pair(x + 1, y));
			visited[x + 1][y]=true;
			index++;
			flag = true;
		}
		if (!visited[x - 1][y] && arr[x - 1][y] > 0 && abs(arr[x][y] - arr[x-1][y]) >= l && abs(arr[x][y] - arr[x-1][y]) <= r) {
			sum += arr[x - 1][y];
			deq.push_back(make_pair(x - 1, y));
			deq2.push_back(make_pair(x - 1, y));
			visited[x - 1][y]=true;
			index++;
			flag = true;
		}
		if (!visited[x][y - 1] && arr[x][y - 1] > 0 && abs(arr[x][y] - arr[x][y - 1]) >= l && abs(arr[x][y] - arr[x][y - 1]) <= r) {
			sum += arr[x][y - 1];
			deq.push_back(make_pair(x, y - 1));
			deq2.push_back(make_pair(x, y - 1));
			index++; visited[x][y - 1]=true;
			flag = true;
		}
	}

	if (flag) {//바뀌었으면 검사
		sum /= index;
		for (int i = 0; i < deq2.size(); i++) arr[deq2[i].first][deq2[i].second] = sum;
	}
}

int main() {
	
	cin >> n >> l >> r;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			cin >> arr[i][j];
	
	int check = 0;

	while (1) {

		if (flag) break;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
			{
				if(!visited[i][j]) bfs(i, j);
			}
		}

		//flag가 참이 되면 바뀌는 것이 있다.
		//flag가 참이 아니면 와일문 종료

		if (!flag) break;
		else flag = false;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
			{
				visited[i][j] = false;
			}
		}

		check++;
	}
	cout << check;
}