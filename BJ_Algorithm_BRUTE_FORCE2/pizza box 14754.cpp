#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, sum = 0, arrsum=0;

int arr[1001][1001];

vector<pair<int, int>> vec;

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j]; arrsum += arr[i][j];
		}
	}

	//front
	for (int i = 0; i < m; i++)
	{
		int Max = 0; pair<int, int> pos;

		for (int j = n - 1; j >= 0; j--) {
			if (Max < arr[j][i]) {
				Max = arr[j][i];
				pos = make_pair(j, i);
			}
		}
		vec.push_back(pos);
	}

	//side
	for (int i = 0; i < n; i++)
	{
		int Max = 0; pair<int, int> pos;

		for (int j = 0; j < m; j++) {
			if (Max < arr[i][j]) {
				Max = arr[i][j];
				pos = make_pair(i, j);
			}
		}
		vec.push_back(pos);
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		sum += arr[vec[i].first][vec[i].second];
	}

	cout << arrsum-sum;
}