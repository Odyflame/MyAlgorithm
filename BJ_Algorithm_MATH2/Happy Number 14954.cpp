/*
*2015112119 by 이현재
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

		if(find(vec.begin(), vec.end(), sum) == vec.end())//못 찾았을 경우
			vec.push_back(sum);
		else {//찾았을 경우
			flag = true;//unhappy
			break;
		}
	}

	if (flag) cout << "UNHAPPY";
	else cout << "HAPPY";
}