#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int t, n, arr[2][100001], dp[100001][2];

int main() {
	cin >> t;

	for (int k = 0; k < t; k++) {
		cin >> n;
		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];

		dp[0][0] = arr[0][0];
		dp[0][1] = arr[1][0];

		dp[1][0] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];

		for (int i = 2; i < n; i++) {
			dp[i][0] = max(max(dp[i - 1][0], arr[0][i] + dp[i - 1][1]), arr[0][i] + dp[i - 2][1]);
			dp[i][1] = max(max(dp[i - 1][1], arr[1][i] + dp[i - 1][0]), arr[1][i] + dp[i - 2][0]);
		}

		cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
	}
}
