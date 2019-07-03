#include <iostream>

using namespace std;

long long arr[6] = { 0,1,1,1,2,2 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << arr[n] << endl;
	}


}