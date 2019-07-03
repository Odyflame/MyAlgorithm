
/*2015112119 by 이현재*/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool desc(int a, int b) {
	if (a >= 0 || b >= 0) return a < b;
	else return a > b;
}

int main() {
	int Number, Sum=0, Count=0, Count2=0;
	vector<int> myVec;
	cin >> Number;

	myVec.resize(Number);
	for (int i = 0; i < Number; i++) {
		cin >> myVec[i];
		if (myVec[i] < 0) Count++;
		if (myVec[i] == 0) Count2++;
	}

	sort(myVec.begin(), myVec.end(), desc);
	//for (auto ele : myVec) cout << ele << " ";

	if (Number > 1) {//Number가 2 이상인 경우
		for (int i = Number; i > 0; i--) {
			if (i>1 && myVec[i - 1] * myVec[i - 2] > 0 && myVec[i - 1] * myVec[i - 2] >= myVec[i-1] + myVec[i-2]) {
				
				Sum += myVec[i - 1] * myVec[i - 2];
				i--;
				
			}
			else if (myVec[i - 1] == 0 && Count == 1) {//0을 발견한경우
				i--;
			}
			else if (i == 1 && Count > 1 && Count % 2 == 1 && Count2 > 0) {

			}
			else {
				Sum += myVec[i - 1];
			}
			
		}
		cout << Sum;
	}
	else if (Number == 1) cout << myVec[0];
	else cout << 0;
}