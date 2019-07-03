#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <deque>
#include <string>

using namespace std;

int main() {
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int len = min(abs(w - x), abs(h - y));
	len = min(x,len);
	len = min(y, len);
	cout << len;
}