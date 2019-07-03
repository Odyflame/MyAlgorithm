#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

bool broken[10];

int possible(int x) {
	int len = 0;

	if (x == 0) {
		if (broken[0]) return 0;
		else return 1;
	}

	while (x > 0) {
		if (broken[x % 10]) return 0;
		len++;
		x /= 10;
	}
	return len;
}

int main() {
	int n, m;

	cin >> n >> m;

	int temp;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		broken[temp] = true;
	}

	int answer = n - 100;

	answer = abs(answer);

	for (int i = 0; i <= 1000000; i++) {
		int c = i;
		int finalanswer = possible(c);

		if (finalanswer > 0) {
			int press = c - n;
			press = abs(press);
			if (answer > finalanswer + press) answer = finalanswer + press;
		}
	}
	cout << answer;
}