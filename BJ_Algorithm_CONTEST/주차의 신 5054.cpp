#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int testcase;

	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int n, a;
		vector<int> vec;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a;
			vec.push_back(a);
		}

		sort(vec.begin(), vec.end());

		cout << 2 * (vec[vec.size() - 1] - vec[0]) << '\n';
	}
}