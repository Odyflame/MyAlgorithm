#include <iostream>

using namespace std;

int main() {
	int n, m, Min = 9999999, Max = -9999999;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		Min = Min < m ? Min : m;
		Max = Max > m ? Max : m;
	} cout << Min << " " << Max;
}