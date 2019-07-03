
/*2015112119 by ÀÌÇöÀç*/

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

set<string> vec;
set<string> dbj;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string s;
	pair<set<string>::iterator, bool> pr;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		vec.insert(s);
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		pr = vec.insert(s);
		if (pr.second == false) {
			dbj.insert(s);
		}
	}

	cout << dbj.size() << '\n';
	for (auto ele : dbj) cout << ele << '\n';
}