#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

int main() {
	
	string srr;

	cin >> srr;

	int top = 0, lazer, sum=0, lazervec;
	
	vector<char> vec;

	for (int i = 0; i < srr.size(); i++) {
		
		if (srr[i] == '(') {
			vec.push_back(srr[i]);
		}
		else {//')'
			vec.pop_back();
			if (srr[i-1] == '(') {
				sum += vec.size();
			}
			else {
				sum++;
			}
		}
	}

	cout << sum;
}