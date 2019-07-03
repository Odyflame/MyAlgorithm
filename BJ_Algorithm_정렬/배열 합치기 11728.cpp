#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <deque>
#include <string>

using namespace std;

int main() {
	int n, m, temp;
	cin >> n >> m;

	vector<int> arr;
	vector<int> arr2;
	vector<int> arr3;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		arr2.push_back(temp);
	}

	merge(arr.begin(), arr.end(), arr2.begin(), arr2.end(), back_inserter(arr3));

	for (auto ele : arr3) cout << ele<<" ";
}