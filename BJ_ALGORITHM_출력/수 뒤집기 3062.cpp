#include <iostream>
#include <string>

using namespace std;

int main() {
	int t, n, cnt=0;
	string s;
	string ab;
	string srr;

	int sum = 0;
	cin >> t;

	for (int j = 0; j < t; j++) {
		cin >> s;
		ab = s;
	
		for (int i = 0; i < s.length(); i++) {
			ab[i] = s[s.length() - i - 1];
		}

	}
}