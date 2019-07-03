#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;
int arr[20][20];
int n, Max = 99999;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	vector<int> vec(n/2);
	
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];

	for (int i = 0; i < n/2; i++) vec.push_back(1);
	sort(vec.begin(), vec.end());

	do {
		int teama = 0, teamb = 0;
		vector<int> teamavec, teambvec;
		for (int i = 0; i < n; i++) {
			if (vec[i]) teamavec.push_back(i);
			else teambvec.push_back(i);
		}

		for (int i = 0; i < n/2; i++) {
			for (int j = 0; j < n/2; j++) {
				teama += arr[teamavec[i]][teamavec[j]];
				teamb += arr[teambvec[i]][teambvec[j]];
			}
		}

		if (Max > abs(teama - teamb)) Max = abs(teama - teamb);

	} while ( next_permutation(vec.begin(), vec.end()) );

	cout << Max;
	return 0;
}