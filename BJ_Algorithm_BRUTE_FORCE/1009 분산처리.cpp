/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, a, b;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;

		if (a % 10 == 0) {
			cout << 10 << endl; continue;
		}
		
		if (a > 10) { a = a % 10; }

		switch (a)
		{
		case 1: cout << 1 << endl; break;
		case 2: b %= 4; if (b == 0) b = 4; a = pow(a, b); a %= 10; cout << a << endl; break;
		case 3: b %= 4; if (b == 0) b = 4; a = pow(a, b); a %= 10; cout << a << endl; break;
		case 4: b %= 2; if (b == 0) b = 2; a = pow(a, b); a %= 10; cout << a << endl; break;
		case 5: cout << 5 << endl; break;
		case 6: cout << 6 << endl; break;
		case 7: b %= 4; if (b == 0) b = 4; a = pow(a, b); a %= 10; cout << a << endl; break;
		case 8: b %= 4; if (b == 0) b = 4; a = pow(a, b); a %= 10; cout << a << endl; break;
		case 9: b %= 2; if (b == 0) b = 2; a = pow(a, b); a %= 10; cout << a << endl; break;
		default:
			break;
		}
	}
}