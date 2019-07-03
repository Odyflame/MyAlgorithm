#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1001], dp[1001], amx, answer = -1;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		amx = 0;

		for (int j = 0; j < i; j++) if (arr[i] < arr[j]) amx = max(amx, dp[j]);
		dp[i] = amx + 1;
		answer = max(answer, dp[i]);
	}
	cout << answer;
}