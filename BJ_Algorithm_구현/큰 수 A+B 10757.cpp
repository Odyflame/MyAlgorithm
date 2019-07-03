#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <deque>
#include <string>

using namespace std;

int main() {
	string srr;
	string srr2;

	deque <char> deq;
	cin >> srr >> srr2;

	int len = max(srr.size(), srr2.size());
	int minlen = min(srr.size(), srr2.size());

	reverse(srr.begin(), srr.end());
	reverse(srr2.begin(), srr2.end());

	int x = 0;
	char temp = 'a';
	for (int i = 0; i < minlen; i++) {
		if (minlen > i) {
			if (x + srr[i] - '0' + srr2[i] - '0' > 9) {
				temp = srr[i] - '0' + srr2[i] - '0' + x - 10 + '0';
				x = 1;
				deq.push_back(temp);
			}
			else {
				temp = srr[i] - '0' + srr2[i] - '0' + x + '0';
				x = 0;
				deq.push_back(temp);
			}
		}
	}

	for (int i = minlen; i < len; i++) {
		if (srr.size() == minlen) {
			if (x + srr2[i] - '0' > 9) {
				temp = srr2[i] - '0' + x - 10 + '0';
				x = 1;
				deq.push_back(temp);
			}
			else {
				temp = srr2[i] - '0' + x + '0';
				x = 0;
				deq.push_back(temp);
			}
		}
		else {
			if (x + srr[i] - '0' > 9) {
				temp = srr[i] - '0' + x - 10 + '0';
				x = 1;
				deq.push_back(temp);
			}
			else {
				temp = srr[i] - '0' + x + '0';
				x = 0;
				deq.push_back(temp);
			}
		}
	}

	if (x == 1) deq.push_back('1');

	reverse(deq.begin(), deq.end());

	for (auto ele : deq) cout << ele;
}