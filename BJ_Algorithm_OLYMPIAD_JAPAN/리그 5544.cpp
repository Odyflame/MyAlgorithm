#include <iostream>
#include <algorithm>

using namespace std;
pair<int, int> arr[102][102];
int team[102];

int main() {
	

	int Rank[102];
	int n, A,B,C,D;

	cin >> n;

	for (int i = 0; i < n*(n - 1) / 2; i++) {
		cin >> A >> B >> C >> D;

		if(A < B) arr[A][B] = make_pair(C, D);
		else arr[B][A] = make_pair(D, C);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (i == j) continue;

			if (arr[i][j].first > arr[i][j].second) {
				team[i] += 3;
			}
			else if (arr[i][j].first == arr[i][j].second) {
				team[i] += 1; team[j] += 1;
			}
			else {
				team[j] += 3;
			}
		}
	}

	for (int i = 0; i <= n; i++) Rank[i] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (team[i] > team[j]) Rank[j]++;
			else if (team[i] < team[j]) Rank[i]++;
		}
	}

	for (int i = 1; i <= n; i++) cout << Rank[i] << '\n';
}