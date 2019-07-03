#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int testcase, n, m, x, y;

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int possible() {
	int tempx=0, tempy = 0;

	for (int i = 0; i < n; i++) {
		tempx = i * m + x;

		if ((tempx-1) % n + 1 == y) return tempx;
	}

	return -1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> m >> n >> x >> y;

		int finalanswer;

		finalanswer = possible();

		if (finalanswer > lcm(m, n)) cout << -1<<'\n';
		else cout << finalanswer<<'\n';
	}
}