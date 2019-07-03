#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class mysort {
public:
	string myword;

	mysort(string s="") :myword(s) {}

	friend bool operator <(const mysort & ms, const mysort & ms2) {
		if (ms.myword.length() == ms2.myword.length()) return ms.myword < ms2.myword;
		else return ms.myword.length() < ms2.myword.length();
	}

	friend bool operator ==(const mysort & ms, const mysort & ms2) {
		return ms.myword == ms2.myword;
	}
};

int main() {
	int n;
	string word;

	vector<mysort> vec;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> word;
		
		mysort ms(word);

		if (find(vec.begin(), vec.end(), ms) != vec.end()) continue;
		else vec.push_back(ms);
	}

	sort(vec.begin(), vec.end());

	for (auto ele : vec) cout << ele.myword << "\n";
}