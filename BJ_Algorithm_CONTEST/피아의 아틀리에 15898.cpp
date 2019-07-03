#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n;//재료 개수
int Max = 0; //최대값
int sum;
bool visited[10];
int check = 0;

pair<int, char> gama[5][5];//처음 가마
pair<int, char> material[10][4][4][4];//재료 순서, 회전 순서, 재료 값들

pair<int, char> dp[5][5];

//a는 원본, b는 재료, 재료 색 합치기
pair<int, char> add(pair<int, char> a, pair<int, char> b) {
	pair<int, char> c;
	c.first = a.first + b.first;

	if (c.first < 0) c.first = 0;
	else if (c.first > 9) c.first = 9;

	if (b.second == 'W')c.second = a.second;
	else c.second = b.second;

	return c;
}

//합을 나타나게 할 때 해주는 함수
int getvalue(pair<int, char> dp[][5]) {
	int r = 0, b = 0, g = 0, y = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (dp[i][j].second == 'R') r += dp[i][j].first;
			else if (dp[i][j].second == 'B') b += dp[i][j].first;
			else if (dp[i][j].second == 'G') g += dp[i][j].first;
			else if (dp[i][j].second == 'Y') y += dp[i][j].first;
		}
	}
	return 7 * r + 5 * b + 3 * g + 2 * y;
}

void dfs(int cnt, pair<int, char> dp[5][5]) {
	if (cnt == 3) {

		sum = 0;
		sum=getvalue(dp);

		if (Max < sum) Max = sum;

		return;
	}

	for (int t = 0; t < n; t++) {//재료 순서
		if (!visited[t]) {
			visited[t] = true;

			for (int i = 0; i < 2; i++) {//위치
				for (int j = 0; j < 2; j++) {

					for (int rotate = 0; rotate < 4; rotate++) {

						pair<int, char> temp[5][5];

						for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) temp[i][j] = dp[i][j];

						for (int w = 0; w < 4; w++) {
							for (int e = 0; e < 4; e++) {
								temp[w + i][e + j] = add(temp[w+i][e+j] ,material[t][rotate][w][e]);
							}
						}
							
						dfs(cnt + 1, temp);
					}
				}
			}

			visited[t] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//가마값 입력
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) gama[i][j] = { 0,'W' };

	//재료값 입력
	cin >> n;

	//h는 재료수, 재료들의 값 입력
	for (int h = 0; h < n; h++) {
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cin >> material[h][0][i][j].first;

		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cin >> material[h][0][i][j].second;
	}

	//k에는 4방향으로 회전했을 때의 값이 저장됨
	for (int h = 0; h < n; h++) {

		pair<int, char> temp[4][4];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				material[h][1][i][j] = material[h][0][3 - j][i];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				material[h][2][i][j] = material[h][1][3 - j][i];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				material[h][3][i][j] = material[h][2][3 - j][i];
			}
		}

	}
	//material안에는 회전한 정보 모두가 저장되어있다

	//dp 초기화
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) dp[i][j] = gama[i][j];

	memset(visited, false, sizeof(visited));

	dfs(0, dp);

	cout << Max;
}


