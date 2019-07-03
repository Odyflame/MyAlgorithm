#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class employee {
public:
	int age;
	string name;

	employee(int x=0, string key="") : age(x), name(key){}

	friend bool operator<(const employee & em1, const employee & em2) {
		return em1.age < em2.age;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, age;
	string name;
	cin >> n;

	vector<employee> vec;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;

		employee em(age, name);

		vec.push_back(em);
	}

	//기존의 순서를 보장해주는 stable_sort
	stable_sort(vec.begin(), vec.end());

	for (auto ele : vec) cout << ele.age << " " << ele.name << '\n';
}