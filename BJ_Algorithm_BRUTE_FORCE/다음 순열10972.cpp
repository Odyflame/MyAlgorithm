/*
*2015112119 by ������
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int swap(int a, int b) {
	return a > b ? a : b;
}

int main() {

	int n;

	cin >> n;

	vector<int> v(n);
	vector<int> v2(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v2[i] = n - i;
	}

	//�ؽ�Ʈ �۹̼��� �迭�� ���� ���� �ذ����ִ� ���ϴ�.
	cout << next_permutation(v.begin(), v.end()) << endl;
	if (!next_permutation(v.begin(), v.end())) {
		cout << -1 << endl;
		return 0;
	}

	else {
		next_permutation(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		return 0;
	}
	
	//���� �ȿ��� return 0;�� ���� ������ �Ǿ� �� ���� �ڵ�� ���� �ʴ� ���ϴ�.
	cout << -1 << endl;
}