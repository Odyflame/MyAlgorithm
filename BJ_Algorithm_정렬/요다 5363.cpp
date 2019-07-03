#include <iostream>
#include <string>
#include <sstream>//문자열 스트림
#include <vector>
using namespace std;

int main() {
	int n;
	string s, srr;
	vector<string> vec;
	cin >> n;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	for (int i = 0; i < n; i++) {
		
		vec.clear();
		getline(cin, s);
		
		for (stringstream sts(s); sts >> srr;) vec.push_back(srr);
		
		for (int i = 2; i < vec.size(); i++) cout << vec[i] << " ";
		for (int i = 0; i < 2; i++) cout << vec[i] << " ";
		cout << endl;
	}


}