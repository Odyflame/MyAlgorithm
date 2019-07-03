#include<iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, a, operand = 0;
	string calcu;
	cin >> n;
	cin >> calcu;

	vector<char> vec;
	vector<int> arr_vec;
	vector<double> final_vec;

	for (int i = 0; i < calcu.size(); i++) {
		vec.push_back(calcu[i]);
		if (calcu[i] >= 'A' && calcu[i] <= 'Z') operand++;
	}

	for (int i = 0; i < n; i++) {
		cin >> a;
		arr_vec.push_back(a);
	}

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] >= 'A' && vec[i] <= 'Z') {
			int temp = vec[i] - 65;
			vec[i] = 48 + arr_vec[temp];
		}
	}

	for (int i = 0; i < vec.size(); i++) {

		if (vec[i] == '*' || vec[i] == '+' || vec[i] == '-' || vec[i] == '/') {
			double a = final_vec.back();
			final_vec.pop_back();
			double b = final_vec.back();
			final_vec.pop_back();
			double c;

			if (vec[i] == '*') c = a * b;
			else if (vec[i] == '+') c = a + b;
			else if (vec[i] == '-') c = b - a;
			else if (vec[i] == '/') c = b / a;

			final_vec.push_back(c);
		}
		else final_vec.push_back(vec[i] - 48);
	}

	cout << fixed;
	cout.precision(2);
	cout << final_vec.back();
}