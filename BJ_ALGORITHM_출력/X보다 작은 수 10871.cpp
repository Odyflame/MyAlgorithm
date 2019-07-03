#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, x, c;
	vector<int> vec;

	cin >> a >> x;
	
	for (int i = 0; i < a; i++) {
		cin >> c;
		if(c<x) vec.push_back(c);
	}for (auto ele : vec) cout << ele << " ";
}