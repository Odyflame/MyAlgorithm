/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>

using namespace std;

int main() {
	int a, b, v, snail=0, cnt=0;

	cin >> a >> b >> v;

	while (snail < v) {
		snail += a;
		if (snail == v) break;
		snail -= b;
		cnt++;
	}
	cout << cnt + 1;
}