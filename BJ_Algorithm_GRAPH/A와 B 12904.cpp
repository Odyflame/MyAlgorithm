#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a, b;

int main() {

	cin >> a;
	cin >> b;
	bool check = false;

	while (true) {
		if (a.length() == b.length()) {
			if (a == b) check = true;
			break;
		}
		char s = b[b.length() - 1];
		b.erase(b.length() - 1);
		if (s == 'B') reverse(b.begin(), b.end());
	}

	if (check) cout << 1;
	else cout << 0;
}