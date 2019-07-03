#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int t, n, dp[100001];
	memset(dp, -1, sizeof(dp));

	cin >> t;
	dp[1] = 1;
	for (int i = 2; i <= 100000; i++) {
		if (i % 2 == 0 && dp[i] == -1) {
			dp[i] = i;
		}
		else if (i % 2 == 1 && dp[i] == -1) {
			int temp = i;
			while (temp != 1) {
				if (temp % 2 == 0) temp /= 2;
				else 
			}
		}
	}


	for (int i = 0; i < t; i++) {
		cin >> n;

		
	}
}