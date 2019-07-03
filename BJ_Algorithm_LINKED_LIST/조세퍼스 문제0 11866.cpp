/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> qu;
queue<int> temp;

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) qu.push(i);

	cout << "<";

	while (!qu.empty()) {

		for (int i = 1; i < m; i++) {
			if (qu.empty()) break;
			int x = qu.front();
			qu.pop();
			qu.push(x);
		}

		int x = qu.front();
		qu.pop();
		temp.push(x);
	}

	int len = temp.size();
	for (int i = 0; i < len; i++) {
		cout << temp.front();
		if(i!=len-1) cout << ", ";
		temp.pop();
	}
	cout << ">";
}