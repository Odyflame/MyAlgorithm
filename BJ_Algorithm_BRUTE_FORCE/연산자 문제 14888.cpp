/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n,cnt=0;
	int arr[102] = { 0, };
	int arr2[4] = { 0, };
	int sum = 0,maxsum= -1000000000, minsum= 1000000000;
	vector<int> oper2(1);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < 4; i++) { cin >> arr2[i]; sum += arr2[i]; }

	oper2.resize(sum);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < arr2[i];j++) {
			oper2[cnt++] = i;
		}
	}
	//oper2.resize(cnt);

	do{
		sum = 0;
			sum += arr[0];
			for (int i = 0; i < n-1; i++) {
				if (oper2[i] == 0) sum += arr[i + 1];
				else if (oper2[i] == 1)sum -= arr[i + 1];
				else if (oper2[i] == 2)sum *= arr[i + 1];
				else if (oper2[i] == 3)sum /= arr[i + 1];
			} 
		
		maxsum = maxsum > sum ? maxsum : sum;
		minsum = minsum < sum ? minsum : sum;
	} while (next_permutation(oper2.begin(),oper2.end()));

	cout << maxsum << '\n' << minsum;

	return 0;
}