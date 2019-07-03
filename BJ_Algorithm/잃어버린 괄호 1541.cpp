
/*2015112119 by 이현재*/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string srr;

	cin >> srr;
	vector<char> myOp;
	vector<string> myNum;
	for (int i = 0; i < srr.size(); i++) {
		if (srr[i] == '-' || srr[i] == '+') {
			
			myOp.push_back(srr[i]);
			srr[i] = ' ';

		}
	}

	stringstream ss;
	ss.str(srr);
	string temp;
	
	while (ss >> temp) {
		myNum.push_back(temp);
	}

	int sum = stoi(myNum[0]);

	bool flag = true;
	

	for (int i = 0; i < myOp.size(); i++) {
		if (myOp[i] == '+') {
			if (flag) sum += stoi(myNum[i + 1]);//true일 경우 그냥 더해준다.
			else {//괄호가 쳐져있는경우
				sum -= stoi(myNum[i + 1]);
			}
		}
		else {
			if (!flag) {//괄호가 쳐져있는경우
				sum -= stoi(myNum[i + 1]);
			}
			else {
				sum -= stoi(myNum[i + 1]);
				flag = false;
			}

		}
	}cout << sum;
}