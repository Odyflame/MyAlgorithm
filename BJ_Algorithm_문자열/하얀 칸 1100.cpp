#include <iostream>

using namespace std;

int main() {
	int arr[8][8], check=0, cnt=0;
	char chess[8][8];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			arr[i][j] = check;
			if (check == 0) check++;
			else check--;
		}
		if (check == 0) check++;
		else check--;
	}

	for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) cin >> chess[i][j];

	for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) if (arr[i][j] == 0 && chess[i][j] == 'F') cnt++;

	cout << cnt;
}