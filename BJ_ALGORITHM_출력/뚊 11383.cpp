#include <iostream>
#include <string>
using namespace std;

int n, m, cnt = 0;
string s[10], s2[10], s3[10];

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) cin >> s2[i];

	for (int j = 0; j < n; j++) {
		s3[j] = s[j] + s[j];
		for (int i = 0; i < 2 * m; i++) {
			s3[j][i] = s[j][i / 2];
		}
		if (s3[j] == s2[j]) cnt++;
	}

	if (cnt == n) cout << "Eyfa";
	else cout << "Not Eyfa";
}