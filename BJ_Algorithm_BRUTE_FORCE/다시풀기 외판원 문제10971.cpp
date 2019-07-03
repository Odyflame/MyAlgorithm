/*
*2015112119 by ������
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int N;
	int sum, finalsum = 99999998;
	cin >> N;
	int arr[10][10];

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
		v[i] = i;
	}

	do
	{
		sum = 0;
		for (int i = 0; i < N-1; i++) {
			if (arr[v[i]][v[i + 1]] == 0) sum += 100000;
			else sum += arr[v[i]][v[i + 1]];
		}
		if(arr[v[N - 1]][v[0]]!=0) sum += arr[v[N - 1]][v[0]];
		else continue;

		//algorithm���� std::min�� �ִ�. �װ��� �ᵵ �ɵ��ϴ�
		finalsum = (finalsum < sum) ? finalsum : sum;
	} while (next_permutation(v.begin(), v.end()));

	cout << finalsum;
}