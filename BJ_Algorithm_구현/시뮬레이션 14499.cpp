#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <deque>
using namespace std;

int mymap[21][21];
//int dice[4][3] = { 0, };
int dice[6] = { 0, };
int n, m, x, y, k, temp;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	
	cin >> n >> m >> y >> x >> k;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> mymap[i][j];

	for (int i = 0; i < k; i++) {
		int order;
		cin >> order;

		int nx = x + dx[order - 1];
		int ny = y + dy[order - 1];

		if (!(nx >=0 && nx <n && ny>=0 && ny < m))
			continue;
		
		order--;
		switch (order)
		{
		case 0://µ¿

			swap(dice[2], dice[0]);
			swap(dice[0], dice[3]);
			swap(dice[3], dice[5]);

			/*temp = dice[1][0];
			dice[1][0] = dice[1][1];
			dice[1][1] = dice[1][2];
			dice[1][2] = dice[3][1];
			dice[3][1] = temp;*/

			break;
		case 1://¼­

			swap(dice[3], dice[0]);
			swap(dice[0], dice[2]);
			swap(dice[2], dice[5]);

			/*temp = dice[1][2];
			dice[1][2] = dice[1][1];
			dice[1][1] = dice[1][0];
			dice[1][0] = dice[3][1];
			dice[3][1] = temp;*/

			break;
		case 2://ºÏ
			
			swap(dice[4], dice[5]);
			swap(dice[0], dice[4]);
			swap(dice[1], dice[0]);

			/*temp = dice[3][1];
			dice[3][1] = dice[2][1];
			dice[2][1] = dice[1][1];
			dice[1][1] = dice[0][1];
			dice[0][1] = temp;*/

			break;
		case 3://³²

			swap(dice[1], dice[0]);
			swap(dice[0], dice[4]);
			swap(dice[4], dice[5]);

			//temp = dice[0][1];
			//dice[0][1] = dice[1][1];//¹Ù´Ú¸éÀº Ç×»ó 1, 1
			//dice[1][1] = dice[2][1];
			//dice[2][1] = dice[3][1];
			//dice[3][1] = temp;

			break;
		default:
			break;
		}

		if (mymap[nx][ny] == 0) 
			mymap[nx][ny] = dice[5];
			//mymap[nx][ny] = dice[1][1];
		else {
			/*dice[1][1] = mymap[nx][ny];
			mymap[nx][ny] = 0;*/
			dice[5] = mymap[nx][ny];
			mymap[nx][ny] = 0;
		}

		 cout << dice[0] << '\n';

		x = nx; y = ny;
	}
}