#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b, i, cnt=0, x,y;
	bool check = false;
	vector<int> vec;
	cin >> a >> b;

	for (i = 1; i * i < b; i++) { if (b % i == 0) { vec.push_back(i); vec.push_back(b / i); } }

	if (i*i == b) vec.push_back(i);

	for (i = 0; i < vec.size(); i++) {

		y = b / vec[i];
		if (check) break;
		if (y <= 0) break;
		else {
			if (2 * (vec[i] + y) == a - 4) {
				check = true;
				if (y > vec[i]) cout << y + 2 << " " << vec[i]+2;
				else cout << vec[i] + 2 << " " << y + 2;
			}
		}

	}

	// x+2*y+2 = a+b x+y+4 = a
	//2x+2y=a-4, xy=b 
	//y=b/x;
}