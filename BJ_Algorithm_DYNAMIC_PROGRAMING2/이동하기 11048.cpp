/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int dp[1001][1001];
int arr[1001][1001];
int n, m, Max = 0;

int main() {
	cin >> n >> m;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> arr[i][j];

	dp[1][1] = arr[1][1];
	for (int i = 1; i <= n; i++) for (int j = 0; j <= m; j++) {

		if (j + 1 <= m && dp[i][j + 1] < dp[i][j] + arr[i][j + 1])
			dp[i][j + 1] = dp[i][j] + arr[i][j + 1];

		if (i + 1 <= n && dp[i + 1][j] < dp[i][j] + arr[i + 1][j])
			dp[i + 1][j] = dp[i][j] + arr[i + 1][j];

		if (j + 1 <= m && i + 1 <= n && dp[i + 1][j + 1] < dp[i][j] + arr[i + 1][j + 1])
			dp[i + 1][j + 1] = dp[i][j] + arr[i + 1][j + 1];
	}

	cout << dp[n][m];
}