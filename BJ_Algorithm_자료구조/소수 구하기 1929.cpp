#include <iostream>
int ck[1000001] = { 1,1 }, n, a,b;
using namespace std;

int main() {
	for (int i = 2; i <= 1e6; i++) if (!ck[i]) {
		for (int j = i * 2; j <= 1e6; j += i) ck[j] = 1;
	}

	cin >> a >> b;

	for (int i = 1; i < 1e6; i++) {
		if (!ck[i]) {
			if (i > b) break;
			if (i >= a && i <= b) cout << i << '\n';
		}
	}

	return 0;
}