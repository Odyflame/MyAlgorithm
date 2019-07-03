#include <iostream>

using namespace std;

int main() {
	int hamburger[3], soda[2];
	int Min = 9999, sum = 0;

	for (int i = 0; i < 3; i++) cin >> hamburger[i];
	for (int i = 0; i < 2; i++) cin >> soda[i];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			sum = 0;
			sum = hamburger[i] + soda[j];

			if (Min > sum) Min = sum;
		}
	}

	cout << Min - 50;
}