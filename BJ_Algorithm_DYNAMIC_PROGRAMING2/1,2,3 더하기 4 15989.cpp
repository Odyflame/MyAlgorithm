/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <string.h>
#include <map>
#include <queue>

using namespace std;
int dp[100003];
int main() {
	int testcase, a;
	cin >> testcase;

	dp[0] = 1;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j < 100000; j++) {

			if(j-i>=0)
			dp[j] += dp[j - i];

		}
	}

	for (int i = 0; i < testcase; i++) {
		cin >> a; cout << dp[a]<<'\n';
	}
}