#include <iostream>
#include <math.h>
using namespace std;

int n, arr[1000][1000], x, y, k = 0, find_answer;
//배열을 지역 변수로 선언하게되면, 크기의 제약을 받게 됩니다. (1001*1001 = 약 100만)
//그럼 런타임 에러가 나겠죠 ? ?
//하지만, 전역 변수(main 함수 밖)로 배열을 선언하게 된다면, 이러한 제약이 사라지는 것으로 알고 있습니다.
int main() {

	bool check=false;
	cin >> n >> find_answer;

	arr[n / 2][n / 2] = 1;

	for (int i = n; i > 1; i -= 2) {
		check = false; x = 0, y = 0;
		for (int j = pow(i, 2); j >= pow(i - 2, 2) + 1; j--) {
			if (!check && y == 0) {//check=false
				arr[k+x][k+y] = j;
				x++;
				if (x == i) {
					check = true; x--; continue;
				}
				continue;
			}else if (check==true && x==i-1) {//check=ture
				y++;
				arr[k + x][k + y] = j;
				if (y == i - 1) {
					check = false; continue;
				}
				continue;
			}else if (!check && x >= 0) {//check=false;
				x--;
				arr[k + x][k + y]=j;
				if (x == 0) {
					check = true; continue;
				}
				continue;
			}else if (check && y > 0) {//check=true
				y--;
				arr[k + x][k + y] = j;
				if (x == 0 && y == 1) break;
				continue;
			}
		}
		k++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
			if (arr[i][j] == find_answer) {
				x = i; y = j;
			}
		}cout << '\n';
	}

	cout << x + 1 << " " << y + 1;
} 