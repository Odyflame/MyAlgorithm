#include <iostream>
#include <string>

using namespace std;

class ONE {
public:
	int weight;
	ONE(int a = 1) :weight(a + 2) {}
	~ONE() {}
	void print() {
		for (int i = 0; i < weight; i++) cout << " ";
		cout << " ";
	}
};

class TWO {
public:
	int weight;
	TWO(int a = 1) :weight(a + 2) {}
	~TWO() {}
	void print() {
		for (int i = 0; i < weight; i++) {
			if (i == 0 || i == weight - 1) cout << " ";
			else cout << "-";
		}cout << " ";
	}
};

class THREE {
public:
	int weight;
	THREE(int a = 1) :weight(a + 2) {}
	~THREE() {}
	void print() {
		for (int j = 0; j < weight; j++) {
			if (j == weight - 1) cout << "|"; else cout << " ";
		}cout << " ";
	}
};

class FOUR {
public:
	int weight;
	FOUR(int a = 1) :weight(a + 2) {}
	~FOUR() {}
	void print() {
		for (int j = 0; j < weight; j++) {
			if (j == 0 || j == weight - 1) cout << "|"; else cout << " "; 
		}cout << " ";
	}
};

class FIVE {
public:
	int weight;
	FIVE(int a = 1) :weight(a + 2) {}
	~FIVE() {}
	void print() {
		for (int j = 0; j < weight; j++) {
			if (j == 0) cout << "|"; else cout << " "; 
		}cout << " ";
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int s, height;
	string srr;

	cin >> s >> srr;

	ONE one(s);
	TWO two(s);
	THREE three(s);
	FOUR four(s);
	FIVE five(s);

	height = 2 * s + 3;

	for (int i = 0; i < height; i++) {
		if (i == 0) {
			for (int j = 0; j < srr.size(); j++) {
				if (srr[j] == '1' || srr[j] == '4') one.print();
				else two.print();
			}
		}
		else if (i == height - 1) {
			for (int j = 0; j < srr.size(); j++) {
				if (srr[j] == '1' || srr[j] == '4' || srr[j] == '7') one.print();
				else two.print();
			}
		}
		else if (i == (height / 2)) {
			for (int j = 0; j < srr.size(); j++) {
				if (srr[j] == '1' || srr[j] == '7' || srr[j] == '0') one.print();
				else two.print();
			}
		}
		else if (i < (height / 2)) {
			for (int j = 0; j < srr.size(); j++) {
				if (srr[j] == '1' || srr[j] == '2' || srr[j] == '3' || srr[j] == '7') three.print();
				else if (srr[j] == '5' || srr[j] == '6') five.print();
				else four.print();
			}
		}
		else if (i > (height / 2)) {
			for (int j = 0; j < srr.size(); j++) {
				if (srr[j] == '6' || srr[j] == '8' || srr[j] == '0') four.print();
				else if (srr[j] == '2') five.print();
				else three.print();
			}
		}cout << "\n";
	}
}