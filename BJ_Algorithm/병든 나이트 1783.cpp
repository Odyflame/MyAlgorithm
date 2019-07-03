
/*2015112119 by ÀÌÇöÀç*/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int main() {
	long long int n, m;

	cin >> n >> m;
	
	int x = 0;

	if (n == 1) cout << 1;
	else if (n == 2) {
		
		if ((m + 1) / 2 > 4) cout << 4;
		else cout << (m + 1) / 2;

	}
	else {
		if (m >= 7) {
			cout << 5 + m - 7;
		}
		else {
			if (m <= 1) cout << 1;
			else if (m <= 2) cout << 2;
			else if (m <= 3) cout << 3;
			else if (m <= 6) cout << 4;
		}
	}
}