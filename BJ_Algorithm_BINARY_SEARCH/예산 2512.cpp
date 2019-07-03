/*

* 2015112119 ÀÌÇöÀç 

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long n, sum = 0, mymax, Max = 0, sum2 = 0;
unsigned long long arr[10001];
bool check = true;

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; sum += arr[i];
	}
	cin >> mymax;
	sort(arr, arr + n);

	vector<long long> vec;

	unsigned long long left = 0; unsigned long long right = mymax;
	unsigned long long mid = (left + right) / 2;

	while (left < right) {
		sum2 = 0;
		for (int i = 0; i < n; i++) {
			if (mid < arr[i]) sum2 += mid;
			else sum2 += arr[i];
		}
		if (sum2 > mymax) {
			right = mid;
			mid = (left + right) / 2;
		}
		else {
			if (sum2 <= mymax) {
				Max = mid;
			}
			left = mid + 1;
			mid = (left + right) / 2;
		}
	}cout << Max;
}