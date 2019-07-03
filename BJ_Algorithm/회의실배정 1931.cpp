/*2015112119 by ÀÌÇöÀç*/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>

using namespace std;

int number = 0;
int arr[100001][2];
int x, y;
vector<pair<int, int>> vec;

bool desc(pair<int,int> a, pair<int,int> b) {
	if (a.second != b.second)return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	cin >> number;

	for (int i = 0; i < number; i++) {
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}

	sort(vec.begin(), vec.end(), desc);

	//for (auto ele : vec) cout << ele.first <<" "<< ele.second << "\n";

	if (number > 0) {

		int count = 1;
		int start = vec[0].second;

		for (int i = 1; i < number; i++) {
			if (vec[i].first < start) continue;
			else {
				start = vec[i].second;
				count++;
			}
		}
		cout << count;
	}
	else cout << 0;
}