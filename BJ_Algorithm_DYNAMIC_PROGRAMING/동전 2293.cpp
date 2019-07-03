#include <iostream>

using namespace std;

int sum = 0, Count=0, n,k;

int dp[100004];

int main() {
	int n, k, coin[101];
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coin[i]) dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[k];
}
