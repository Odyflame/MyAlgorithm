#include <iostream>

using namespace std;

int main() {
	int n, temp,sum,min;
	bool check;
	cin >> n;

	for (int i = 0; i < n; i++) {
		sum = 0;
		min = 9999;
		check = false;
		for (int j = 0; j < 7; j++) {
			cin >> temp;

			if (temp % 2 == 0) {
				check = true;
				sum += temp;
				min = min > temp ? temp : min;
			}
		}
		if (check) cout << sum << " " << min << endl;
		else cout << sum << " " << 0 << endl;
	}
}