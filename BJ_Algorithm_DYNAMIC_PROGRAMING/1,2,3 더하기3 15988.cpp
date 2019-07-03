#include <iostream>

using namespace std;

int t;
long long n;
long long arr[1000004] = { 0,1,2,4 };

int main() {
	cin >> t;

	for (int i = 4; i <= 1e6; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3])%1000000009;
	}

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << arr[n] << endl;
	}
}