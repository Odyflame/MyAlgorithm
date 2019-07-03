/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>

using namespace std;

void bs(int left, int right, int mid) {
	
}

int main() {
	int n, arr[10001], c, sum=0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; sum += arr[i];
	}

	cin >> c;

	int left = 0, right = sum / n;
	int mid = left + right / 2 + 1;

}