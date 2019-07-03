#include <iostream>

using namespace std;

long long int first = 1, second = 1;
long long int arr(long long int sum, int n, int count) {
	
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (count == n)	return sum;

	sum = (first + second);
	first = second;
	second = sum;
	count++;
	arr(sum, n, count);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, n;
	long long int sum=1;

	cin >> n;

	cout << arr(sum, n, 2);
}