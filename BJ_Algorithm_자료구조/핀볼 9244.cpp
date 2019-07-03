#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool desc(pair< pair<int, int>, pair<int, int>> a, pair< pair<int, int>, pair<int, int>> b) {
	int amin = min(a.first.second, a.second.second);
	int bmin = min(b.first.second, b.second.second);
	return amin > bmin;
}

int main() {
	deque < pair< pair<int, int>, pair<int, int>>> vec;

	int linenumber, x1, y1, x2, y2, ball;

	cin >> linenumber;

	for (int i = 0; i < linenumber; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		vec.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
	}

	sort(vec.begin(), vec.end(), desc);

	cin >> ball;

	for (int i = 0; i < 2 * linenumber; i++) {

		if (vec.empty()) break;
		int j = 0;
		if (vec[j].first.first < vec[j].second.first) {
			if ((ball >= vec[j].first.first && ball <= vec[j].second.first)) {
				if (vec[j].first.second > vec[j].second.second) ball = vec[j].second.first;
				else ball = vec[j].first.first;
				vec.pop_front();
			}
			else {
				pair< pair<int, int>, pair<int, int>> temp2 = vec.front();
				vec.pop_front();
				vec.push_back(temp2);
			}
		}
		else if (vec[j].first.first >= vec[j].second.first) {
			if ((ball <= vec[j].first.first && ball >= vec[j].second.first)) {
				if (vec[j].first.second > vec[j].second.second) ball = vec[j].second.first;
				else ball = vec[j].first.first;
				vec.pop_front();
			}
			else {
				pair<pair<int, int>, pair<int, int>> temp2 = vec.front();
				vec.pop_front();
				vec.push_back(temp2);
			}
		}
	}

	std::cout << ball;
}