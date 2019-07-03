#include <iostream>

using namespace std;

int main() {
	//빠른 문자열 처리하기 
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int star;
	cin >> star;

	for (int i = star; i > 0; i--) cout << i << '\n';
}