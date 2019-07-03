#include <iostream>

using namespace std;

int main() {
	int n, arr[31] = { 3,11,41 };
	cin >> n;

	if (n % 2 == 1) cout << 0;
	else {
		for (int i = 3; i < (n / 2); i++) arr[i] = arr[i - 1] * 3 + arr[i - 2] * 3 - arr[i - 3];
		cout << arr[(n / 2)-1];
	}
}