#include <iostream>
#include <string.h>
using namespace std;

int arr[101][101], T, H, W, N, Count;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		memset(arr, -1, sizeof(arr));
		Count = 1;
		try {
			for (int i = 1; i <= W; i++) {
				for (int j = H; j >= 1; j--) {
					if (Count == N) {
						if (i < 10)	cout << H - j + 1 << 0 << i;
						else cout << H-j + 1<< i;
						cout << endl;
						throw 1;
					}
					arr[j][i] = 1;
					Count++;
				}
			}
		}
		catch (...) {}
	}
}