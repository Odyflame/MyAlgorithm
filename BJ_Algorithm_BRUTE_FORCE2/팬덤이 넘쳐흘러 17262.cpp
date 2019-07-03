///*
//*2015112119 by ÀÌÇöÀç
//*/
//#include <iostream>
//#include <algorithm>
//#include <list>
//#include <vector>
//#include <string>
//
//using namespace std;
//int n, a, b, Min=9999999, Max=-1;
//
//int arr[100002];
//int brr[100002];
//
//int main() {
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		cin >> a >> b;
//		for (int i = a; i <= b; i++) {
//			arr[i]++;
//			if(i!=b) brr[i]++;
//		}
//		if (Min > a) Min = a;
//		if (Max < b) Max = b;
//	}
//
//	vector<int> vec;
//
//	for (int i = Min; i <= Max; i++) {
//		vec.push_back(arr[i]);
//	}
//
//	sort(vec.begin(), vec.end());
//
//	cout << vec.front();
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <string>
#include <string.h>
#include <time.h>
#include <deque>
#include <math.h>


using namespace std;

int n;
bool flag = false;
int function(int start) {

	int a = 0, b = 0, sum = 0;

	if (start == n && flag) {
		cout << "not happy number;";
		return 0;
	}
	else if (start == 1) {
		cout << "happy number";
		return 0;
	}

	a = start;

	if (a >= 10) {
		while (a > 0) {

			int Count = 0;
			b = a;
			while (b >= 10) {
				b = b / 10;
				Count++;
			}
			sum += pow(b, 2);

			a = a - b * pow(10, Count);
		}
	}
	else {
		sum += pow(a, 2);
	}
	flag = true;

	function(sum);

	return -1;
}

int main() {

	cin >> n;
	function(n);


	return 0;
}