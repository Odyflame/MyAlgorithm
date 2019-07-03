#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[1002];
int testcase, n, k, d, w, x, y, Max;

int main() {
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		vector<int> buildtime;
		vector<int> linked_tower[1002];//오른쪽
		int left_linked_tower[1002] = { 0, };//왼
		int dp[1001] = { 0, };
		Max = 0;
		int sum = 0;

		cin >> n >> k;

		for (int j = 0; j < n; j++) {
			cin >> d;
			buildtime.push_back(d);
		}

		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			linked_tower[x-1].push_back(y-1);
			left_linked_tower[y - 1]++;
		}

		cin >> w;

		queue<int> qu;

		for (int j = 0; j < n; j++) {
			if (left_linked_tower[j] == 0) qu.push(j);
		}

		while (left_linked_tower[w - 1]>0) {
			int top = qu.front();
			qu.pop();

			for (auto ele : linked_tower[top]) {
				left_linked_tower[ele]--;
				
				dp[ele] = max(dp[top] + buildtime[top], dp[ele]);

				if (left_linked_tower[ele] == 0) {
					qu.push(ele);
				}

			}//선행 간선 제거

		}
		cout << dp[w-1] + buildtime[w-1]<< '\n';
	}
}