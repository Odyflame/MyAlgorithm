#include <iostream>

using namespace std;

long long room[1000001];
long long n, a, b, c, sum = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		room[i] = a;
	}
	cin >> b >> c;

	sum += n;

	for (int i = 0; i < n; i++) {
		room[i] -= b;
		if (room[i] < 0) room[i] = 0;

		if (room[i] > 0) {
			if (room[i] <= c) sum++;
			else {
				if (room[i] % c == 0) sum += (room[i] / c);
				else sum += (room[i] / c) + 1;
			}
		}
	}

	cout << sum;
}