#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, sex, grade, room_sum = 0;

void calculate(vector<int> &vec) {
	if (vec.empty()) {
		room_sum++;
		vec.push_back(1);
	}
	else {
		vec.push_back(1);
		if (vec.size() == k) vec.clear();
	}
}

int main() {

	cin >> n >> k;

	vector<int> man[6];
	vector<int> woman[6];

	for (int i = 0; i < n; i++) {
		cin >> sex >> grade;

		if (sex) calculate(man[grade - 1]);
		else calculate(woman[grade - 1]);
	
	}

	cout << room_sum;
}