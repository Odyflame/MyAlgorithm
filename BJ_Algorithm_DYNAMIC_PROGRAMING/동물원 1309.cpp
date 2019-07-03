#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n, dp[100001];

	cin >> n;

	dp[0] = 0;
	dp[1] = 3;
	dp[2] = 7;
	dp[3] = 17;

	for (int i = 4; i <= n; i++) { dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901; }
	
	cout << dp[n];
}