/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>


using namespace std;

int main() {
	int n, m, x, count=0;
	int arr[10001];
	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		cin >> x;
		arr[i] = x;
	}x = 0;

	for (int i = 0; i < n; i++) {
		x = 0;
		for (int j = i; j < n; j++) {
			x += arr[j];
			if (x == m) count++;
			if (x > m) break;
		}
	}cout << count;
}