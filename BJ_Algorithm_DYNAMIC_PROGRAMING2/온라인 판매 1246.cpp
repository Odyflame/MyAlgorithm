#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, egg, price, max_egg, max_price, max_sum=0;

	cin >> n >> m;

	vector<int> man_price;
	for(int i=0;i<m;i++){
		cin >> price;
		man_price.push_back(price);
	}

	sort(man_price.begin(), man_price.end());

	int final_price = 0;
	for (int i = 0; i < m; i++) {
		int sum = 0;
		max_egg = 0;

		max_price = man_price[i];
		
		for (int j = i; j < m; j++) {
			if (max_egg >= n) break;

			if (max_price <= man_price[j]) {
				sum += man_price[j];
			}
		}

		if (max_sum < sum) {
			max_sum = sum;
			final_price = max_price;
		}
	}

	cout << final_price <<" "<< max_sum;
}