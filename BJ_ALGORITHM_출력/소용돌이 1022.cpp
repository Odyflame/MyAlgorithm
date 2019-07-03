#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[10000][10000];

int main() {

	int r1, c1, r2, c2, Max = 0, max2=0, x, y, k=0, max3, max4, maxValue=0;
	bool check, check2, check3, check4;
	cin >> r1 >> c1 >> r2 >> c2;

	Max = abs(r1) > abs(r2) ? abs(r1) : abs(r2);
	max2 = abs(c1) > abs(c2) ? abs(c1) : abs(c2);
	Max = Max > max2 ? Max : max2;

	max3 = Max;
	max4 = Max;

	Max = Max * 2 + 1;
	k = Max-1;

	for (int i = Max; i > 1; i -= 2) {
		check = true; x = 0, y = 0; check2 = false; check3 = false; check4= false;
		for (int j = pow(i, 2); j >= pow(i - 2, 2) + 1; j--) {

			if (check && !check2 &&!check3 && !check4 ) {//check=false
				if (k + x >= r1 + max3 && k + x <= r2 + max3 && k + y >= c1 + max3 && k + y <= c2 + max3)
				{
					arr[k + x][k + y] = j;
					maxValue = max(maxValue, arr[k + x][k + y]);
				}
				y--;
				if (y == -i) {
					check = false; y++; check2 = true;
				}
				continue;
			}
			else if (!check && check2 && !check3 && !check4) {//check=ture
				x--;
				if (k + x >= r1 + max3 && k + x <= r2 + max3 && k + y >= c1 + max3 && k + y <= c2 + max3) { arr[k + x][k + y] = j; maxValue = max(maxValue, arr[k + x][k + y]); }
				
				if (x == -i + 1) {
					check2 = false; check3 = true;
				}
				continue;
			}
			else if (!check && !check2 && check3 && !check4) {//check=false;
				y++;
				if (k + x >= r1 + max3 && k + x <= r2 + max3 && k + y >= c1 + max3 && k + y <= c2 + max3) { arr[k + x][k + y] = j; maxValue = max(maxValue, arr[k + x][k + y]); }

				if (y == 0) {
					check3 = false;  check4 = true;
				}
				continue;
			}
			else if (!check && !check2 && !check3 && check4) {//check=true
				x++;
				if (k + x >= r1 + max3 && k + x <= r2 + max3 && k + y >= c1 + max3 && k + y <= c2 + max3)
				{
					arr[k + x][k + y] = j;
					maxValue = max(maxValue, arr[k + x][k + y]);
				}
				if (j== pow(i - 2, 2) + 1) break;
			}
		}k--;
	}

	if (k + x >= r1 + max3 && k + x <= r2 + max3 && k + y >= c1 + max3 && k + y <= c2 + max3) arr[max4][max4] = 1;

	int valuesize=0;
	for (; maxValue>0; maxValue /= 10) valuesize++;

	for (int i = r1 + max3; i <= r2 + max3; i++) {
		for (int j = c1 + max3; j <= c2 + max3; j++) {
			printf("%*d ", valuesize, arr[i][j]);//cout <<" "<< arr[i][j] << " ";
		}printf("\n");
	}
}