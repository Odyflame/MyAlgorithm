#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int main() {

	cin >> n;
	long long *arr = new long long[n];

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);
	long long Min = -999999;
	long long *temp = new long long[n];
	temp = arr;
	do {
		long long sum = 0;

		for (int i = 0; i < n - 1; i++) {
			sum += arr[i] * arr[i + 1];
		}
		
		if (Min < sum) {
			Min = sum;
			for (int i = 0; i < n; i++) {
				temp[i] = arr[i];
			}
		}

	} while (next_permutation(arr, arr + n));

	for (int i = 0; i < n; i++) cout << temp[i] << " ";
}