#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int n; char bu;
	vector <char> vec;
	vector<int> myvec;
	vector<int> myvec2;
	vector<int> Max, Min;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> bu;
		vec.push_back(bu);
	}

	for (int i = 0; i <= n + 1; i++) {
		myvec.push_back(i); myvec2.push_back(9 - i);
	}

	do {
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (vec[i] == '<') {
				if (myvec2[i] > myvec2[i + 1]) {
					flag = false;
					break;
				}
			}
			else {//'>'
				if (myvec2[i] < myvec2[i + 1]) {
					flag = false;
					break;
				}
			}
		}
		if (!flag) continue;

		for (int i = n+1; i > 0; i--) {
			Max.push_back(myvec2[n  - (i - 1)]);
		}
		break;

	} while (prev_permutation(myvec2.begin(), myvec2.end()));

	do {
		bool flag = true;
		for (int i = 0; i < vec.size(); i++) {

			if (vec[i] == '<') {
				if (myvec[i] > myvec[i + 1]) {
					flag = false;
					break;
				}
			}
			else {//'>'
				if (myvec[i] < myvec[i + 1]) {
					flag = false;
					break;
				}
			}

		}

		if (!flag) continue;

		for (int i = n + 1; i > 0; i--) {
			Min.push_back(myvec[n - (i-1)]);
		}
		break;

	} while (next_permutation(myvec.begin(), myvec.end()));

	for (auto ele : Max) cout << ele;
	cout << '\n';
	for (auto ele : Min) cout << ele;
}