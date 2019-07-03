/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>

using namespace std;

int main() {
	long long n,sum=1;

	cin >> n;

	for (int i = 1; i <= n; i++) sum *= i;
	cout << sum;
}