#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s, srr, sum="";
	vector<string> vec;
	bool check1 = false, check2 = false, check3 = false, check4 = false, check5=false;
	getline(cin, s);

	for (stringstream sts(s); sts >> srr;) vec.push_back(srr);
	
	for (int i = 0; i < s.size(); i++) if (s[i] == 'U' || s[i] == 'P' || s[i] == 'C') sum += s[i];
	
	if (sum.size() < 4) cout << "I hate UCPC";
	else {
		for (int i = 0; i < sum.size(); i++) {
			if (sum[i] == 'U' && check1 == false) {
				check1 = true;
			}
			if (sum[i] == 'C' && check1 == true) {
				check2 = true;
			}
			if (sum[i] == 'P' && check2 == true) {
				check3 = true;
			}
			if (sum[i] == 'C' && check3 == true) {
				check4 = true;
			}
		}

		if (check4) cout << "I love UCPC";
		else cout << "I hate UCPC";
	}
}