#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, dp[100501], arr[320], icheck, Count=0, Min=999, temp;
	memset(dp, 9999, sizeof(dp));

	cin >> n;

	for (int i = 1; i < 321; i++) {
		if (i*i > n) {
			icheck = i - 1;
			break;
		}
		arr[i] = i * i;
	}

	dp[0] = 0;
	
	//동전 교환 알고리즘
	for (int i = 1; i <= icheck; i++) {
		for (int j = arr[i]; j <= n; pow(++j,2)) {
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}

	cout << dp[n];
}