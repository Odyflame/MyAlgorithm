#include <iostream>

using namespace std;

bool visited[21], visited2[21];
int arr[21];
int n, s;
int cnt = 0;

void dfs(int start, int sum, int check, int mycheck) {

	if (visited[start] && visited2[start]) return;

	if (check >= mycheck) {
		if (sum == s) {
			cnt++;
		}
		return;
	}

	sum += arr[start];
	visited[start] = true;

	for (int i = start+1; i < n; i++) {
		if(!visited[start] && !visited2[start])
		dfs(i, sum, check + 1, mycheck);
	}

	visited[start] = false;
	
	return;
}

int main() {

	cin >> n >> s;

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			dfs(i, 0, 0, j);
		}visited2[i] = true;
	}

	if (s == 0) cnt--;
	cout << cnt;
}