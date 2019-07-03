#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
int arr3[9];
bool arr2[9];

void dfs(int depth) {

	if (depth == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		if (!arr2[i]) {
			arr2[i] = true;
			arr[depth]=(arr3[i]);
			dfs(depth + 1);
			arr2[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr3[i];

		for (int j = 0; j < i; j++) {
			if (arr3[i] < arr3[j]) {
				int temp = arr3[i];
				arr3[i] = arr3[j];
				arr3[j] = temp;
			}
		}
	}

	dfs(0);
}