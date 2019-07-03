/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <vector>

#define LIMIT 300000

using namespace std;

int main() {
	vector<bool> isprime(LIMIT + 1, true);

	for (int i = 2; i < 1000; i++) {
		for (int j = i * i; j <= LIMIT; j += i) {
			isprime[j] = false;
		}
	}

	int n, sum = 0;

	cin >> n;

	isprime[2] = true;

	while (n != 0) {
		sum = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (isprime[i]) sum++;
		}

		cout << sum << '\n';

		cin >> n;
	}
}