#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
	string a, b;

	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	istringstream istr1(a);
	istringstream istr2(b);

	int A, B;
	istr1 >> A;
	istr2 >> B;
	
	if (A > B) cout << A;
	else cout << B;
}