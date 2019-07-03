#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cin.tie(NULL);
	int n, Min=999999;
	cin >> n;

	int *arr = new int[n];
	vector<int> myarr;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		myarr.push_back(i);
	}

	sort(arr, arr + n);

	int sum = 0;
	int finalsum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		finalsum += sum;
	}

	//do {
	//	int sum = 0;
	//	int finalsum = 0;
	//	for (int i = 0; i < n; i++) {
	//		sum += arr[myarr[i]];
	//		finalsum += sum;
	//	}
	//	Min = min(finalsum, Min);
	//} while (next_permutation(myarr.begin(), myarr.end()));

	cout << finalsum;
}