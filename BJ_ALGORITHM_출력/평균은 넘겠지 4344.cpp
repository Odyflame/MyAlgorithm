#include <iostream>

using namespace std;

double n, arr[1001], dp[1001], amx = 0, k, cnt=0.0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		amx = 0; cnt = 0;
		for (int j = 0; j < k; j++) {
			cin >> arr[j];
			amx += arr[j];
		}

		for (int j = 0; j < k; j++) {
			if (amx / k < arr[j]) cnt++;
		}

		cout.setf(ios::fixed);
		cout.precision(3);
		cout << cnt/k*100 << "%\n";
	}
}