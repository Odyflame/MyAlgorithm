
/*2015112119 by 이현재*/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

/*bool desc(int a, int b) {
	return a > b;
}

int main() {
	long long int Number, temp=0;
	vector<long long int> myVec;

	cin >> Number;

	while (Number) {
		temp = Number % 10;
		Number /= 10;
		myVec.push_back(temp);
	}

	sort(myVec.begin(), myVec.end(), desc);
	//for (auto ele : myVec) cout << ele << " ";

	bool flag = false;
	long long int Sum;
	
	do {
		Sum = 0;
		for (int i = myVec.size()-1; i >= 0; i--) {
			Sum += myVec[i] * pow(10, myVec.size() - 1 - i);
		}
		//cout << Sum <<'\n';
		if (Sum % 30 == 0) {
			flag = true; break;
		}
	} while (next_permutation(myVec.begin(), myVec.end()));

	if (!flag) cout << -1;
	else cout << Sum;
}*/

bool zeroFlag = false;

bool desc(char a, char b) {
	if (a == '0' || b == '0') zeroFlag = true;
	return a > b;
}

int main() {
	string srr;

	cin >> srr;

	sort(srr.begin(), srr.end(), desc);

	bool flag = false;
	long long int Sum;

	if (!zeroFlag) {//false 0이 아무것도 없을경우 
		cout << -1;
	}
	else {
		do {
			Sum = 0;
			for (int i = srr.size() - 1; i >= 0; i--) {
				Sum += (srr[i]-'0');
			}
			//cout << Sum <<'\n';
			if (Sum % 3 == 0) {
				flag = true; 
				for (auto ele : srr) cout << ele;
				break;
			}
		} while (next_permutation(srr.begin(), srr.end()));

		if (!flag) cout << -1;
	}
}