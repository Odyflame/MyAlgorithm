/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, k, Count = 0, Next;

int visited[200002] = { 0, };
int dp[200002];
long long cnt[200002];
queue<int> arr;

int bfs(int N, int K) {
	if (N >= K) return n - k;

	arr.push(N);
	visited[N] = 1;
	cnt[N] = 1;
	while (!arr.empty()) {
		int arr_size = arr.size();
		for (int i = 0; i < arr_size; i++) {

			Next = arr.front();
			arr.pop();
			if (Next == K) return Count;
			if (visited[Next - 1] == 0 && Next > 0) {
				arr.push(Next - 1); visited[Next - 1] = 1;
				dp[Next - 1] = dp[Next] + 1;
				cnt[Next - 1] = cnt[Next];
			}else if(dp[Next-1]==dp[Next] + 1) cnt[Next - 1] += cnt[Next];
			
			if (visited[Next + 1] == 0 && Next < 100000) {
				arr.push(Next + 1); visited[Next + 1] = 1;
				dp[Next + 1] = dp[Next] + 1;
				cnt[Next + 1] = cnt[Next];
			}
			else if (dp[Next + 1] == dp[Next] + 1) cnt[Next + 1] += cnt[Next];

			if (visited[Next * 2] == 0 && 2 * Next <= 100000) { 
				arr.push(2 * Next); visited[Next * 2] = 1; 
				dp[Next * 2] = dp[Next] + 1;
				cnt[Next * 2] = cnt[Next];
			}
			else if (dp[Next * 2] == dp[Next] + 1) cnt[Next * 2 ] += cnt[Next];
		}

		Count++;
	}

	return Count;
}

int main() {
	cin >> n >> k;

	if (n == k) cout << 0 << '\n' << 1;
	else {
		cout << bfs(n, k) << '\n';
		cout << cnt[k];
	}
}