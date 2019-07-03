#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string srr;
	vector <string> vec;
	vector<int> final_vec;
	for (int i = 0; i < 5; i++) {
		cin >> srr;
		vec.push_back(srr);
	}

	for (int i = 0; i < 5; i++) {
		
		if (vec[i].size() >= 3) {
			for (int j = 0; j < vec[i].size() - 2; j++) {
				if (vec[i][j] == 'F' && vec[i][j + 1] == 'B'&&vec[i][j + 2] == 'I') { final_vec.push_back(i); break; }
			}
		}

	}
	if(final_vec.size()>0) for (auto ele : final_vec) cout << ele+1 << " ";
	else cout << "HE GOT AWAY!";
}