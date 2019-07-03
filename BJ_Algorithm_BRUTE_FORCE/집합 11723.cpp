/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, member;
	cin >> n;

	vector<int> S;
	string order;

	for (int i = 0; i < n; i++) {

		cin >> order;

		if (order == "add") {
			cin >> member;
			if (find(S.begin(), S.end(), member) != S.end()) continue;
			else S.push_back(member);
		}
		else if (order == "remove") {
			cin >> member;
			vector<int>::iterator iter = S.begin();
			while (iter != S.end()) {
				if (*iter == member) {
					iter = S.erase(iter);
				}
				else iter++;
			}
		}
		else if (order == "check") {
			cin >> member;
			if (find(S.begin(), S.end(), member) != S.end()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (order == "toggle") {
			cin >> member;
			if (find(S.begin(), S.end(), member) != S.end()) {
				vector<int>::iterator iter = S.begin();
				while (iter != S.end()) {
					if (*iter == member) {
						iter = S.erase(iter);
					}
					else iter++;
				}
			}
			else S.push_back(member);
		}
		else if (order == "all") {
			S.clear();
			for (int j = 1; j <= 20; j++) S.push_back(j);
		}
		else if (order == "empty") {
			S.clear();
		}
	}
}