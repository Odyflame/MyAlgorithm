#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, p, temp, cnt=0;
	vector<int> vec;

	cin >> n >> p;
	temp = n;
	do {
		temp = (temp*n) % p;
		vec.push_back(temp);
	} while (find(vec.begin(), vec.end(), (temp*n) % p) == vec.end());
	
	while (find(vec.begin(), vec.end(), (temp*n) % p) == vec.end()) {
		cnt++;
	}

	cout << vec.size()- cnt;
}