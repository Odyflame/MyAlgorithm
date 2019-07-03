#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() {
	int n, k, price, sum=0;
	vector<int>vec;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> price;
		vec.push_back(price);
	}
	
	sort(vec.begin(), vec.end(), desc);

	for (int i = 0; i < n; i++) {
		if (k >= vec[i]) {
			sum += k / vec[i];
			   k %= vec[i];
		}
	}

	cout << sum;
}