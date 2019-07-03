#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;
int n;
list<char> vec;
string s;
char x, order;
int top = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s;
	cin >> n;

	for (int i = 0; i < s.size(); i++) {
		vec.push_back(s[i]); top++;
	}
	
	list<char>::iterator iter = vec.begin();
	
	for (int i = 0; i < top; i++) iter++;

	for (int i = 0; i < n; i++) {
		cin >> order;

		if (order == 'P') {
			cin >> x;
			vec.insert(iter, x);
		}
		else if (order == 'L') {
			if (iter == vec.begin());
			else iter--;
		}
		else if (order == 'D') {
			if (iter == vec.end());
			else iter++;
		}
		else if (order == 'B') {
			if (iter==vec.begin());
			else {
				iter--;
				vec.erase(iter++);
			}
		}
	}

	

	for (auto ele : vec) cout << ele;
}