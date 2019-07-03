/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>	
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int x1, x2, y1, y2, c1, c2, r, sum=0;

		vector<pair<int, int>> vec;

		cin >> x1 >> y1 >> x2 >> y2;
		int n;
		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> c1 >> c2 >> r;
			if((pow(c1-x1,2) + pow(c2-y1, 2) > pow(r,2) && pow(c1 - x2, 2) + pow(c2 - y2, 2) < pow(r, 2)) 
				|| (pow(c1 - x1, 2) + pow(c2 - y1, 2) < pow(r, 2) && pow(c1 - x2, 2) + pow(c2 - y2, 2) > pow(r, 2)) ) {
				sum++;
			}
		}
		cout << sum << '\n';
	}
}