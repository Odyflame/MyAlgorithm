/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>


using namespace std;

int n, s;
int number[21];
int Count;

void dfs(int idx, int sum)
{
	if (idx >= n) {
		if (sum == s) Count++;
		return;
	}

	dfs(idx + 1, sum);
	dfs(idx + 1, sum + number[idx]);
}

int main()
{
	int i;

	cin >> n >> s;

	for (i = 0; i < n; i++) {
		cin >> number[i];
	}

	dfs(1, 0);
	dfs(1, number[0]);

	if (s == 0) Count--;
	cout << Count;

	return 0;
}