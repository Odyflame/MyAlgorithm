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

	char temp = 'a';
	for (int i = 0; i < minlen; i++) {
		if (minlen > i) {
			temp = srr[i] + srr2[i] - '0' - '0' + '0';
			if (temp > '9') {//11자리인 경우
				temp = temp - '0' - 10 + '0';
				deq.push_back(temp);
				deq.push_back('1');
			}
			else deq.push_back(temp);
		}
	}

	for (int i = minlen; i < len; i++) {
		if (srr.size() == minlen) {
			deq.push_back(srr2[i]);
		}
		else {
			deq.push_back(srr[i]);
		}
	}


	reverse(deq.begin(), deq.end());

	for (auto ele : deq) cout << ele;
}