#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, max_sum=1, final_sum=1;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		cin >> a;
		vec.push_back(a);
	}
	long long mul = -9999;

	sort(vec.begin(), vec.end());

	int xfirst = vec.front();
	int xend = vec.back();

	//��ξ���ų� 0�� ������
	if (xfirst >= 0) {
		mul = vec[vec.size() - 1] * vec[vec.size() - 2];

		if (mul < mul*vec[vec.size() - 3]) {
			mul *= vec[vec.size() - 3];
		}

	}//��������ų� 0�� ������
	else if (xend <= 0) {
		mul = vec[0] * vec[1];

		if (mul < mul*vec[2]) {
			mul *= vec[2];
		}

	}//ó�� �ΰ��� �����ϰ��
	else if (vec[0]<0 && vec[1]<0) {

		if(vec[0] * vec[1]* vec[vec.size() - 1] > vec[vec.size() - 1] * vec[vec.size() - 2] * vec[vec.size() - 3] || vec[0] * vec[1] * vec[vec.size() - 1] > vec[vec.size() - 1] * vec[vec.size() - 2])
		{
			mul = vec[0] * vec[1] * vec[vec.size() - 1];
			if (mul < vec[0] * vec[1]) mul = vec[0] * vec[1];
		}
		else {
			if (vec[0] * vec[1] < vec[vec.size() - 1] * vec[vec.size() - 2]) {
				mul = vec[vec.size() - 1] * vec[vec.size() - 2];

				if (mul < mul*vec[vec.size() - 3]) {
					mul *= vec[vec.size() - 3];
				}

			}
			else {
				mul = vec[0] * vec[1];

				if (mul < mul*vec[vec.size() - 1]) {
					mul *= vec[vec.size() - 1];
				}
			}
		}
	}
	else if(vec[0] < 0){//������ �ϳ��� �����ϰ��
		mul = vec[vec.size() - 1] * vec[vec.size() - 2];

		if (mul < mul*vec[vec.size() - 3]) {
			mul *= vec[vec.size() - 3];
		}
	}


	cout << mul;
}