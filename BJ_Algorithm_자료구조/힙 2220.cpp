#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int main() {

	deque<int> v, finalv;
	int n, sum, finalmax=0;
	cin >> n;

	for (int i = 0; i < n; i++) v.push_back(i+1);
	
	do {
		sum = 0;
		deque<int> temp, temp2;
		temp = v;
		temp2 = v;
		while (!temp.empty()) {

			int max = -1, maxindex=0;
			for (int i = 0; i < temp.size(); i++) {
				if (max < temp[i]) {
					maxindex = i;
					max = temp[i];
				}
			}

			if (temp[0] < max) {
				swap(temp[0], temp[maxindex]);
				sum++;
			}

			temp.pop_front();
		}

		if (finalmax < sum) {
			finalmax = sum;
			finalv = temp2;
		}
	} while (next_permutation(v.begin(), v.end()));
	
	for (auto ele : finalv) cout << ele << " ";
}