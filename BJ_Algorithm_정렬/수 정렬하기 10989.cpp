#include <iostream>
#include <string.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, arr[10001], a;
	memset(arr, 0, sizeof(arr));

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[a]++;
	}

	for (int i = 1; i < 10001; i++) if (arr[i] > 0) for (int j = 0; j < arr[i]; j++) cout << i << '\n';
}