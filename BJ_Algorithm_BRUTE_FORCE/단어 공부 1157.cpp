/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int alphabat[26];
int Count = 0;
int checksum = 0;
int check=97;

int main() {
	string str;

	cin >> str;

	//transform(str.begin(), str.end(), str.begin(), tolower);

	for (int i = 0; i < (int)str.length(); i++)	tolower(str[i]);

	for (int i=0; i < (int)str.length(); i++)
	{
		alphabat[(int)str[i] - 97]++;
	}

	for (int i=0; i < 26; i++)
	{
		if (!alphabat[i]) continue;
		
		if (Count < alphabat[i]) {
			Count = alphabat[i];
			check = i+97;
		}
	}

	for (int i=0; i < 26; i++)
	{
		if (Count == alphabat[i]) checksum += 1;
		if (Count == alphabat[i] && checksum > 1) {
			cout << "?";
			return 0;
		}
	}

	cout << (char)toupper((char)check);
}