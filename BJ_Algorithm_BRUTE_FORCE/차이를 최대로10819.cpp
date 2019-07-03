/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	int n, sum=0, finalsum=0;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	do
	{
		for (int i = 0; i < n - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}

		finalsum = (finalsum > sum) ? finalsum : sum;
		sum = 0;

	} while (next_permutation(v.begin(), v.end()));

	cout<<finalsum;
}