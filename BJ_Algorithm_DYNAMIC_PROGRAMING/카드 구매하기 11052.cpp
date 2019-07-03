#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int n, dp[1001], arr[1001];

int main() {
	memset(dp, -1, sizeof(dp));

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = min(arr[i], dp[i - 1] + dp[1]);
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}

	cout << dp[n];
}