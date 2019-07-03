#include <iostream>

using namespace std;

int main() {
	int n, Count=0;

	cin >> n;
	n = 1000 - n;
	while (n != 0) {
		if (n >= 500) {
			Count += n / 500;
			n %= 500;
		}
		else if (n >= 100) {
			Count += n / 100;
			n %= 100;
		}
		else if (n >= 50) {
			Count += n / 50;
			n %= 50;
		}
		else if (n >= 10) {
			Count += n / 10;
			n %= 10;
		}
		else if (n >= 5) {
			Count += n / 5;
			n %= 5;
		}
		else if (n >= 1) {
			Count += n;
			n =0;
		}
	}
	cout << Count;
}