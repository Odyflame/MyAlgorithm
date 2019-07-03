#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001], n, arr[10001];

int main() {
	cin >> n;
	dp[1] = 0;

	for (int i = 1; i <= n; i++) { cin >> arr[i]; }

	if (n > 3) {
		dp[1] = arr[1];
		dp[2] = dp[1] + arr[2];
		dp[3] = max(arr[1] + arr[2], max(arr[1] + arr[3], arr[2] + arr[3]));

		for (int i = 4; i <= n; i++) {
			dp[i] = max(dp[i - 1], max(arr[i] + arr[i - 1] + dp[i - 3], dp[i - 2] + arr[i]));
		}
	}
	else if(n == 1){
		dp[1] = arr[1];
	}
	else if (n == 2) {
		dp[2] = arr[1] + arr[2];
	}
	else if (n == 3) {
		dp[2] = arr[1] + arr[2];
		dp[3] = max(arr[1] + arr[2], max(arr[1] + arr[3], arr[2] + arr[3]));
	}
	cout << dp[n];
}