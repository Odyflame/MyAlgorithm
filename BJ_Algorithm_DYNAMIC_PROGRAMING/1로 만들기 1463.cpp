#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int dp[1000001], n;
queue<pair<int, int>> qu;
int main() {
	memset(dp, -1, sizeof(dp));

	cin >> n;
	dp[n] = 0;

	for (int i = n; i >= 1; i--) {
		if (i > 1) {
			if (dp[i - 1] == -1) dp[i - 1] = dp[i] + 1;
			else dp[i - 1] = (dp[i - 1] > dp[i] + 1) ? dp[i] + 1 : dp[i - 1];
		}if (i % 2 == 0) {
			if (dp[i / 2] == -1) dp[i / 2] = dp[i] + 1;
			else dp[i / 2] = (dp[i / 2] > dp[i] + 1) ? dp[i] + 1 : dp[i / 2];
		}if (i % 3 == 0) {
			if (dp[i / 3] == -1) dp[i / 3] = dp[i] + 1;
			else dp[i / 3] = (dp[i / 3] > dp[i] + 1) ? dp[i] + 1 : dp[i / 3];
		}
	}

	cout << dp[1];
}