/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(pair<int, int> x, pair<int, int> y) {
	if (x.first == y.first) return x.second < y.second;
	return x.first < y.first;
}

int main() {
	int n , x, y;
	vector < pair<int, int> >vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}
	
	sort(vec.begin(), vec.end(), desc);

	for (auto ele : vec) cout << ele.first << " " << ele.second << '\n';
}