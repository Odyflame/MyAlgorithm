#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[100004];
const int x = 100001;
int main() {
	int n, k, coin[101] ,amx=0;

	cin >> n >> k;
	for (int i = 1; i <= 100001; i++) dp[i] = x;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	sort(coin, coin + n);

	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			if (dp[j] > dp[j - coin[i]] + 1) dp[j] = dp[j - coin[i]] + 1;
		}
	}

	if (dp[k] == x) cout << -1;
	else cout << dp[k];
}