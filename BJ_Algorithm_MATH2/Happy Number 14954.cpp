/*
*2015112119 by ������
*/
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	vector <int> vec;
	bool flag = false;

	cin >> n;
	vec.push_back(n);

	while ( 1 ) {
		int x = vec.back();
		int sum = 0;

		while (x > 0) {
			int last = x % 10;
			sum += pow(last, 2);
			x -= last;
			x /= 10;
		}

		if (sum == 1) { flag = false; break; }

		if(find(vec.begin(), vec.end(), sum) == vec.end())//�� ã���� ���
			vec.push_back(sum);
		else {//ã���� ���
			flag = true;//unhappy
			break;
		}
	}

	if (flag) cout << "UNHAPPY";
	else cout << "HAPPY";
}