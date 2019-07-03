#include <iostream>

using namespace std;

int main() {
	int n;
	int a[500003] = { 0, };

	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	bool change = false;
	for (int i = 1; i <= n + 1; i++) {
		change = false;
		for (int j = 1; j <= n - i; j++) {
			if (a[j] > a[j + 1]) {
				change = true;
				swap(a[j], a[j + 1]);
			}
		}
		if (change == false) {
			cout << i << '\n';
			break;
		}
	}

}