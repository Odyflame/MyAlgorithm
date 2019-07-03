/*
*2015112119 by ÀÌÇöÀç
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector <int> v2(100);
vector <int> v(13);

void DFS(int start, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) cout << v2[i] << " ";
		cout << endl;
		return;
	}

	for (int i = start; i < n; i++) {
		v2[cnt] = v[i];
		DFS(i + 1, cnt+1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) cin >> v[i];
		DFS(0, 0);
		cout << endl;
	}
}