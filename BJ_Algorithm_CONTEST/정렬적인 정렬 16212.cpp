#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int main() {
	
	cin >> n;
	long long *arr = new long long[n];

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) cout << arr[i]<<" ";
}