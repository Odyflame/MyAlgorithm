#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

int visited[27];
int string_Num;
int Max=0;

vector<int> vec;
vector<string> string_vec;
vector<char> char_vec;
string srr;

int calculate() {
	int sum = 0;

	for (int i = 0; i < char_vec.size();i++) visited[char_vec[i] - 65] = vec[i];

	for (string s : string_vec) {
		int now = 0;
		for (char x : s) {
			now = now * 10 + visited[x- 65];
		}
		sum += now;
	}

	return sum;
}

bool desc (string a, string b) {
	return a.length() > b.length();
}

int main() {
	cin >> string_Num;
	
	for (int i = 0; i < string_Num; i++) {
		cin >> srr;
		string_vec.push_back(srr);
	}

	sort(string_vec.begin(), string_vec.end(), desc);

	for (int i = 0; i < string_vec.size(); i++) {
		for (int j = 0; j < string_vec[i].size(); j++) {
			char_vec.push_back(string_vec[i][j]);
		}
	}

	sort(char_vec.begin(), char_vec.end());
	char_vec.erase(unique(char_vec.begin(), char_vec.end()), char_vec.end());

	for (int i = 0; i < char_vec.size(); i++) vec.push_back(9 - i);

	do {
		int temp = calculate();
		if (Max < temp)Max = temp;
	} while (prev_permutation(vec.begin(), vec.end()));

	cout << Max;
}