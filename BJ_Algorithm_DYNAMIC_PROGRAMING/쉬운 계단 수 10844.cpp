#include <iostream>

using namespace std;

int dp[101][11], n, sum=0;

int main() {
	cin >> n;

	dp[1][0] = 0;
	for (int j = 1; j < 10; j++) dp[1][j] = 1;

	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0 ) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9){
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			dp[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) { sum += dp[n][i]; sum %= 1000000000; }
	cout << sum;
}