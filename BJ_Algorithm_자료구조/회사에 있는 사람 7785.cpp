#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int n;
vector<string> employee;
set<string> Employee_order;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	string person, inout;
	for (int i = 0; i < n; i++) {
		cin >> person >> inout;

		if (inout == "enter") {
			Employee_order.insert(person);
		}
		else Employee_order.erase(person);
	}

	for (auto ele = Employee_order.begin(); ele != Employee_order.end(); ele++) employee.push_back(*ele);

	reverse(employee.begin(), employee.end());

	for (auto ele : employee) cout << ele<<'\n';
}