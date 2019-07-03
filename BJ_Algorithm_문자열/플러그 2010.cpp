#include <iostream>

using namespace std;

int main() {
	int n, sum=0, plug;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> plug;
		sum += plug - 1;
	}cout << sum + 1;
}