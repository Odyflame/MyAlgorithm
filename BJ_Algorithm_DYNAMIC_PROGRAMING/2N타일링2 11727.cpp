#include <iostream>

using namespace std;

int first = 1, second = 3;
int arr(int sum, int n, int count) {

	if (n == 1) return first;
	if (n == 2) return second;
	if (count == n)	return sum;

	sum = (2*first + second) % 10007;
	first = second;
	second = sum;
	count++;
	arr(sum, n, count);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, n, sum = 0;

	cin >> n;

	cout << arr(0, n, 2);
}