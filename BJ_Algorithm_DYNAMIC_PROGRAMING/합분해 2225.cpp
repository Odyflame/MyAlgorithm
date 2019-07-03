/*#include <iostream>
#include <string.h>
using namespace std;

int main() {
	long long n, k, dp[250], sum = 0;
	memset(dp, 0, sizeof(dp));

	cin >> n >> k;

	if (k == 1) cout << 1;
	else {
		for (int i = 2; i <= k; i++) {
			for (int j = 0; j <= n; j++) {
				if (i == 2) dp[j] = 1;
				else { if (j > 0) dp[j] = (dp[j] + dp[j - 1]) % 1000000000; }
			}
		}
		for (int i = 0; i <= n; i++) sum = (sum + dp[i]) % 1000000000;
		cout << sum;
	}
}*/

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	long long n, k, dp[100000], sum = 0, check = 0, temp = 0, temp2 = 0;
	memset(dp, -1, sizeof(dp));

	cin >> n >> k;

	if (k == 1) cout << 1;
	else {
		for (int i = 2; i <= k; i++) {
			check = sum;
			sum = 0;
			for (int j = 0; j <= n; j++) {
				if (i == 2) {
					dp[j] = 1;
					sum += dp[j];
				}
				else {
					if (j == 0) {
						temp = dp[0];//21
						dp[0] = check;//220
						sum += dp[0];
					}
					else {
						temp2 = temp;//21
						temp = dp[j];//20
						dp[j] = dp[j - 1] - temp2;
						sum += dp[j];
					}
					dp[j] %= 1000000000;
					sum %= 1000000000;
				}
			}
		}
		cout << sum;
	}
}