/* writed by 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long n, sum=0, max, price=0;
	cin >> n;

	long long *distance = new long long[n-1];
	long long *city = new long long [n];

	for (int i = 0; i < n - 1; i++) {
		cin >> distance[i]; sum += distance[i];
	}
	for (int i = 0; i < n; i++) cin >> city[i];

	max = city[0];
	int cityindex = 0;
	for (int i = 0; i < n - 1; i++) {
		if(i==0)
		price += city[cityindex] * distance[i];
		else {
			if (city[i] < city[cityindex]) {
				cityindex = i;
			}
			price += city[cityindex] * distance[i];
		}
	}

	cout << price;
}