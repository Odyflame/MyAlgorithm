#include <iostream>

using namespace std;

int main() {
	//���� ���ڿ� ó���ϱ� 
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int star;
	cin >> star;

	for (int i = star; i > 0; i--) cout << i << '\n';
}