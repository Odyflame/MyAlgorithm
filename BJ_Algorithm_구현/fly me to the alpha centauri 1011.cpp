#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <deque>
#include <string>
#include <queue>

using namespace std;
bool visited[1000000];
int testcase, x, y, mincnt=999999;

int main() {
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> x >> y;
		queue<int> qu;
		int answer = 0;
		int k = 1;

		int temp = y - x;
		int sum = 0; int check = 0;
		if (temp == 1) cout << 1;
		else if (temp == 2)cout << 2;
		else if (temp == 3) cout << 3;
		else if (temp == 4) cout << 3;
		else if (temp == 5) cout << 4;
		else if (temp == 6) cout << 4;
		else if (temp == 7) cout << 5;
		else if (temp == 8) cout << 5;
		else if (temp == 9) cout << 5;
		else for (int i = 1; i <= temp; i++) {


			sum += i*2;
			

		}

		cout << check <<'\n';
	}
}