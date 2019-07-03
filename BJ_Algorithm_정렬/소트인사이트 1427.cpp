#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() {
	string s;

	cin >> s;
	vector<int> vec;

	for (int i = 0; i < s.size(); i++) {
		char temp = s[i];
		int x = temp - '0';
		vec.push_back(x);
	}

	sort(vec.begin(), vec.end(), desc);

	for (auto ele : vec) cout << ele;
}