/*
*2015112119 by 이현재
*/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <string.h>
#include <map>
#include <queue>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0, 0 };

int main() {
	int n = 3;
	int start = 0;//퍼즐의 모양 

	cout << '\"';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			if (temp == 0) temp = 9;
			start = start * 10 + temp;
		}
	}

	queue<int> qu;
	map<int, int> dist;
	dist[start] = 0;
	qu.push(start);

	while (!qu.empty()) {
		int now_num = qu.front();
		string now = to_string(now_num);
		qu.pop();
		int z = now.find('9');
		int x = z / 3, y = z % 3;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				string next = now;
				swap(next[x * 3 + y], next[nx * 3 + ny]);
				int num = stoi(next);
				if (dist.count(num) == 0) {//dist에 방문한 적이 있는지 없는지 구하라
					dist[num] = dist[now_num]+1;
					qu.push(num);
				}
			}
		}
	}

	if (dist.count(123456789)==0) cout << -1;
	else cout << dist[123456789];
}