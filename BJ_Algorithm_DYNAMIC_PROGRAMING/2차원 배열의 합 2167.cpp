#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, arr[301][301], k, i, j, x, y,sum;

	cin >> n >> m;
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) cin >> arr[i][j];

	cin >> k;

	for (int h = 0; h < k; h++) {
		cin >> i >> j >> x >> y;
		sum = 0;
		for (int r = i; r <= x; r++) {
			for (int e = j; e <= y; e++) {
				sum += arr[r][e];
			}
		}cout << sum << '\n';
	}
}