#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int h, w;
	char c;
	deque<char> cloudChar[100];
	deque<int> cloudInt[100];
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> c;
			cloudChar[i].push_back(c);
			if(c=='c') cloudInt[i].push_back(0);
			else cloudInt[i].push_back(-1);
		}
	}

	int x = 0;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			x = 1;
			cloudChar[j].pop_back();
			cloudChar[j].push_front('.');
		
			for (int q = 0; q < w; q++,x++) {

				if (cloudInt[j][q] == 0) x = 0;
				if (cloudInt[j][q] == -1 && cloudChar[j][q] == 'c')cloudInt[j][q] = x;
				
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << cloudInt[i][j]<<" ";
		}cout << '\n';
	}
}