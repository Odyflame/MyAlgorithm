/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, k=0, cnt=0;
	int arr[4];
	string s;

	cin >> n >> m;
	if (n < m) {
		for (int i = 0; i < n; i++) {
			cout << n;
		}
	}
	else {
		for (int i = 0; i < 4; i++) {

			//s = to_string(n)+s;

			if (n <= 0) break;
			arr[i] = n % 10;
			s += (n % 10)+48;
			n /= 10;
		}

		reverse(s.begin(), s.end());

		for (int i = 0; i < m; i++)	cout << s[i % 4];

	}
}