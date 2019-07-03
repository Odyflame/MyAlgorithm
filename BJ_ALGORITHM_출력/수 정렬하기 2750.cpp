#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vec;
int main() {
	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		vec.push_back(m);
	}

	sort(vec.begin(), vec.end());
	for (auto ele : vec) cout << ele << '\n';
}