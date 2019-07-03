#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
long long arr[100][100];
queue <pair<int,int>> qu;
long long dp[100][100];
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
	
	dp[0][0] = 1;

	//qu.push(make_pair(0, 0));
	/*int tx, ty;
	
	while (!qu.empty()) {
		tx = qu.front().first;
		ty = qu.front().second;
		qu.pop();
		if (tx + arr[tx][ty] < n && ty < n) {
			dp[tx + arr[tx][ty]][ty] += dp[tx][ty];
			if (tx + arr[tx][ty] == n - 1 && ty == n - 1);
			else qu.push(make_pair(tx + arr[tx][ty], ty));
		}
		if (ty + arr[tx][ty] < n && tx < n) {
			dp[tx][ty + arr[tx][ty]] += dp[tx][ty];
			if (tx == n - 1 && ty + arr[tx][ty] == n - 1);
			else qu.push(make_pair(tx, ty + arr[tx][ty]));
		}
	}*/

	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n; j++) {
			if ((i==n-1 && j==n-1) || dp[i][j] == 0) continue;
			if (i + arr[i][j] < n) dp[i + arr[i][j]][j] += dp[i][j];
			if (j + arr[i][j] < n) dp[i][j + arr[i][j]] += dp[i][j];
		}
	}

	cout << dp[n-1][n-1];
}