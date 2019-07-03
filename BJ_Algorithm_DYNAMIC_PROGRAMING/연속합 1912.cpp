#include <iostream>
#include <algorithm>

using namespace std;

int dp[100000], n, arr[100000], sum = 0, check = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	cin >> arr[0];
	dp[0] = arr[0];
	sum = arr[0];
	//������������ Ǯ �� �ð����⵵�� O^2�� 10000�̻��̸� �ð� �ʰ��� �߹Ƿ� �����϶�
	/*for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			dp[i] = max(dp[i], sum);
		}check = max(dp[i], check);
	}*/

	check = dp[0];

	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];

		if (dp[i - 1] + arr[i] > arr[i]) {
			dp[i] = dp[i - 1] + arr[i];
		}
		else {
			dp[i] = arr[i];
		}
		check = max(check, dp[i]);
	}
	cout << check;
}