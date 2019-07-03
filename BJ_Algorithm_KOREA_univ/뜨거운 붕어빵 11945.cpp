/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, m, arr[11][11];
	string s[11];
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
			//cin >> arr[i][j];
			cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = m-1; j >= 0; j--) {
			cout << s[i][j];
		}cout << '\n';
	}
}