/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>

using namespace std;

class squre {
public:
	int x1, y1, x2, y2;
};

int main() {
	for (int i = 0; i < 4; i++) {
		squre sq1;
		squre sq2;
		
		cin >> sq1.x1 >> sq1.y1 >> sq1.x2 >> sq1.y2;
		cin >> sq2.x1 >> sq2.y1 >> sq2.x2 >> sq2.y2;

		if (sq2.x1 > sq1.x2 || sq1.x1 > sq2.x2) {
			cout << 'd';
		}
		else if ((sq1.x2 == sq2.x1 && sq1.y2 == sq2.y1) || (sq1.x2 == sq2.x1 && sq1.y1 == sq2.y2) || (sq2.x2 == sq1.x1 && sq2.y2 == sq1.y1) || (sq2.x2 == sq1.x1 && sq2.y1 == sq1.y2))
			cout << 'c';
	}
}