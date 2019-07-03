/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	int t;
	string s;
	cin >> t;
	unsigned long long a, b;
	for (int i = 0; i < t; i++) {
		cin >> s;

		b = pow(10, s.length() - 1);
		a = 5 * b*(5 * b - 1);
		cout << a<<'\n';
	}
}