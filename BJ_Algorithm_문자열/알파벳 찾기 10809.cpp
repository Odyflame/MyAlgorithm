#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main() {
	string s;
	int alphabet[26];
	cin >> s;
	memset(alphabet, -1, sizeof(alphabet));

	for (int i = 0; i < s.size(); i++) if(alphabet[(int)s[i] - 97]==-1) alphabet[(int)s[i]-97] = i;

	for (int i = 0; i < 26; i++) cout << alphabet[i]<<" ";
}