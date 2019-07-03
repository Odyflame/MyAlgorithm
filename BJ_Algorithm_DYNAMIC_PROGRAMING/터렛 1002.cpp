#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int x1, x2, y1, y2, r1, r2, t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		int distance = (pow(x1 - x2, 2) + pow(y1 - y2, 2));

		if (distance == 0) {
			if (r1 == r2) cout << -1;
			else cout << 0;
		}
		else {
			if ((r1 + r2)*(r1 + r2) > distance && abs(r1 - r2)*abs(r1 - r2) < distance) cout << 2;
			else if ((r1 + r2)*(r1 + r2) == distance || abs(r1 - r2)*abs(r1 - r2) == distance) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
}