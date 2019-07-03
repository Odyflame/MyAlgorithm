/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int n, m, arr[51][51], Max=1, check=1, x, y, check2=0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++)	scanf("%1d", &arr[i][j]);
	
	check2 = max(m, n);
	while (check2 > check) {
		for (int i = 0; i < n - check; i++) for (int j = 0; j < m - check; j++)	if (arr[i][j] == arr[i][j + check] && arr[i][j] == arr[i + check][j] && arr[i][j] == arr[i + check][j + check]) Max = max(Max, (check + 1)*(check + 1));
		check++;
	}
	cout << Max;	
}