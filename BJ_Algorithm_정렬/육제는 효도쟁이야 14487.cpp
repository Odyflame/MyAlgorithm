#include <iostream>

using namespace std;

int main() {
	int n, arr[50001], sum=0, min=99999999;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; sum += arr[i];
	}

	for (int i = 0; i < n; i++)	min = sum - arr[i] > min ? min : sum - arr[i];

	cout << min;
}