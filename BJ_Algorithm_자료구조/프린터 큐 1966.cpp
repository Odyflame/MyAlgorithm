#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque<int> qu;

	int testcase, que_num, myqu, temp, cnt;

	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		qu.clear();
		cnt = 0;
		cin >> que_num >> myqu;

		for (int j = 0; j < que_num; j++) { cin >> temp; qu.push_back(temp); }

		while (!qu.empty()) {
			int x = qu.front();
			bool flag = false;
			for (deque<int>::iterator iter = qu.begin(); iter != qu.end();iter++) {
				if (*iter > x) {

					if(myqu==0) myqu = qu.size() - 1;
					else myqu--;

					temp = qu.front();
					qu.pop_front();
					qu.push_back(temp);
					flag = true;

					break;
				}
			}

			if (!flag) {

				if (myqu == 0) { cout << ++cnt << '\n'; break; }
				qu.pop_front(); cnt++; myqu--;
			}
		}

	}
}