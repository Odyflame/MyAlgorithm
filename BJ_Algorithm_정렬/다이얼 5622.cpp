#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int sum = 0;

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A'&&s[i] <= 'C') sum += 3;
		else if(s[i] >= 'D'&&s[i] <= 'F') sum += 4;
		else if (s[i] >= 'G'&&s[i] <= 'I') sum += 5;
		else if (s[i] >= 'J'&&s[i] <= 'L') sum += 6;
		else if (s[i] >= 'M'&&s[i] <= 'O') sum += 7;
		else if (s[i] >= 'P'&&s[i] <= 'S') sum += 8;
		else if (s[i] >= 'T'&&s[i] <= 'V') sum += 9;
		else if (s[i] >= 'W'&&s[i] <= 'Z') sum += 10;
	}cout << sum;
}

//switch case도 활용할수있다.

/*switch (str[i]) {
case '1':
	ans += 2;
	break;
case 'A': case 'B': case 'C':
	ans += 3;
	break;
case 'D': case 'E': case 'F':
	ans += 4;
	break;*/