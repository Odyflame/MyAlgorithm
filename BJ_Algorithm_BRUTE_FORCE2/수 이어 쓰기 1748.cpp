#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int x, len=0, sum=0;

	cin >> x;

	int temp = x;

	while (temp > 0) {
		temp /= 10;
		len++;
	}

	for (int i = 1; i < len; i++) {
		sum += 9 * pow(10,i-1) * i;
	}

	sum += (x - pow(10, len - 1) + 1)*len;

	cout << sum;
}