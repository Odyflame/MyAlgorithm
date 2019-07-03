#include <iostream>

using namespace std;

int main() {
	int a, b, c, sum = 0;

	cin >> a >> b >> c;


	for (int i = 0; i < a; i++) {
		sum += (i + 1)*(i + 1)*c + (i + 1)*b;
	}
	cout << sum;
}