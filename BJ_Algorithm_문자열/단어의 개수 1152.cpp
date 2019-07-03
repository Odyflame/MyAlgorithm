#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int cnt = 0;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		if (i == 0 && s[i] == ' ') continue;
		if (i== s.length() - 1 && s[i] == ' ') break;
		if (s[i] == ' ') cnt++;
	}

	if (s.length() == 1 && s[0] == ' ') cout << 0;
	else cout << cnt+1;
}