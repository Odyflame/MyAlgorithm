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

	vector<int> man[2];
	vector<int> woman[2];
	vector<int> unisex;

	for (int i = 0; i < n; i++) {
		cin >> sex >> grade;

		if (grade <= 2) calculate(unisex);
		else {
			if (sex) {
				if (grade <= 4) calculate(man[0]);
				else calculate(man[1]);
			}
			else {
				if (grade <= 4) calculate(woman[0]);
				else calculate(woman[1]);
			}
		}
	}

	cout << room_sum;
}