/*
*2015112119 by 이현재
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

	//넥스트 퍼미션이 배열의 다음 순을 해결해주는 듯하다.
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
	
	//메인 안에서 return 0;를 쓰면 리턴이 되어 그 다음 코드는 읽지 않는 듯하다.
	cout << -1 << endl;
}