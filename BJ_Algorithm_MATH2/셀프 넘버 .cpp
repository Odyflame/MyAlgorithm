/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool visited[10001];

int main() {
	for (int i = 1; i <= 10000; i++) {

		if (!visited[i]) {
			int x = i;
			while (x <= 10000) {
				
				int sum = x;

				while (x > 0) {
					int mok = x / 10;
					int last = x % 10;
					sum += last;
					x -= last;
					x /= 10;
				}

				visited[sum] = true;
				x = sum;
			}
		}
	}

	for (int i = 1; i <= 10000; i++) if (!visited[i]) cout << i <<'\n';
}