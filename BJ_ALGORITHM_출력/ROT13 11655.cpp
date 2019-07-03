#include <iostream>
#include <string>

using namespace std;

int main() {

	string s;

	char c;
	while ((c = cin.get()) != '\n') {
		if ((c >= 'A'&&c <= 'Z')) {
			c += 13;
			if (c > 90) {
				int data = c - 90;
				c = 'A';
				c += data - 1;
			}
		}
		if (c >= 'a'&&c <= 'z') {
			if (c >= 's') {
				int data = 'z' - c;
				c = 'a';
				c += 12 - data;
			}
			else if (c > 'm' &&c < 's') {
				c += 13;
				int data = c - 122;
				c = 'a';
				c += data - 1;
			}
			else {
				c += 13;
			}
		}
		s += c;
	}

	cout << s;
}