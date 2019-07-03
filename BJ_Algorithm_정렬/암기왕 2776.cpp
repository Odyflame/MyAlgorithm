#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t, a, b, c;

	cin >> t;

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < t; i++) {
		cin >> a;
		vector<int> vec1;
		for (int j = 0; j < a; j++) {
			cin >> c;
			vec1.push_back(c);
		}

		sort(vec1.begin(), vec1.end());

		cin >> b;
		for (int j = 0; j < b; j++) {
			cin >> c;
			if (binary_search(vec1.begin(), vec1.end(), c)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}