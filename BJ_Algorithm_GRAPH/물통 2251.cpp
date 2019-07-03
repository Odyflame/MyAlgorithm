/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <string.h>
#include <map>
#include <queue>

using namespace std;
bool check[201][201];
vector<int> ccheck;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a, b, c;

	cin >> a >> b >> c;

	queue<pair<pair<int, int>, int>> qu;
	qu.push(make_pair(make_pair(0, 0), c));
	ccheck.push_back(c);
	check[0][0] = true;
	while (!qu.empty()) {
		pair<pair<int, int>, int> xfront = qu.front();
		qu.pop();

		int tx = xfront.first.first, ty = xfront.first.second, tz = xfront.second;
		if (tx == 0);
		else {
			ty += tx;//a->b
			tx = 0;
			if (ty > b) {
				tx = ty - b;
				ty = b;
			}
			if (!check[tx][ty]) {
				check[tx][ty] = true;
				if (tx == 0) ccheck.push_back(tz);
				qu.push(make_pair(make_pair(tx, ty), tz));
			}

			tx = xfront.first.first, ty = xfront.first.second, tz = xfront.second;
			tz += tx;//a->c
			tx = 0;
			if (tz > c) {
				tx = tz - c;
				tz = c;
			}
			if (!check[tx][ty]) {
				check[tx][ty] = true;
				if (tx == 0) ccheck.push_back(tz);
				qu.push(make_pair(make_pair(tx, ty), tz));
			}
		}

		if (ty == 0);
		else {
			tx = xfront.first.first, ty = xfront.first.second, tz = xfront.second;//b->a
			tx += ty;
			ty = 0;
			if (tx > a) {
				ty = tx - a;
				tx = a;
			}
			if (!check[tx][ty]) {
				check[tx][ty] = true;
				if (tx == 0) ccheck.push_back(tz);
				qu.push(make_pair(make_pair(tx, ty), tz));
			}

			tx = xfront.first.first, ty = xfront.first.second, tz = xfront.second;
			tz += ty;//b->c
			ty = 0;
			if (tz > c) {
				ty = tz - c;
				tz = c;
			}
			if (!check[tx][ty]) {
				check[tx][ty] = true;
				if (tx == 0) ccheck.push_back(tz);
				qu.push(make_pair(make_pair(tx, ty), tz));
			}
		}

		if (tz == 0);
		else {
			tx = xfront.first.first, ty = xfront.first.second, tz = xfront.second;
			tx += tz;
			tz = 0;
			if (tx > a) {
				tz = tx - a;
				tx = a;
			}
			if (!check[tx][ty]) {
				check[tx][ty] = true;
				if (tx == 0) ccheck.push_back(tz);
				qu.push(make_pair(make_pair(tx, ty), tz));
			}

			tx = xfront.first.first, ty = xfront.first.second, tz = xfront.second;

			ty += tz;
			tz = 0;
			if (ty > b) {
				tz = ty - b;
				ty = b;
			}
			if (!check[tx][ty]) {
				check[tx][ty] = true;
				if (tx == 0) ccheck.push_back(tz);
				qu.push(make_pair(make_pair(tx, ty), tz));
			}
		}
	}

	sort(ccheck.begin(), ccheck.end());

	for (auto ele : ccheck) cout << ele << " ";

}