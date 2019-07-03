#include <iostream>	
#include <deque>	

using namespace std;

int rightSwap1(deque<int> vec[4], int num) {
	bool flag = true;
	for (int i = 0; i < num; i++) {
		if (flag) {
			int x = vec[i].back();
			vec[i].pop_back();
			vec[i].push_front(x);
		}
		else {
			int x = vec[i].front();
			vec[i].pop_front();
			vec[i].push_back(x);
		}
		flag = !flag;
	}
}

int rightSwap2(deque<int> vec[4], int num) {
	bool flag = true;
	for (int i = 3; i >= num; i--) {
		if (flag) {
			int x = vec[i].back();
			vec[i].pop_back();
			vec[i].push_front(x);
		}
		else {
			int x = vec[i].front();
			vec[i].pop_front();
			vec[i].push_back(x);
		}
		flag = !flag;
	}
}

int clockright(deque<int> vec[4], int num) {//시계방향

	if (num == 1) {
		if (vec[0][2] == vec[1][6])
		{
			rightSwap1(vec, 1);
		}
		else if (vec[1][2] == vec[2][6]) {
			rightSwap1(vec, 2);
		}
		else if (vec[2][2] == vec[3][6]) {
			rightSwap1(vec, 3);
		}
		else {
			rightSwap1(vec, 4);
		}
	}
	else if (num == 4) {

		if (vec[2][2] == vec[3][6])
		{
			rightSwap2(vec, 3);
		}
		else if (vec[2][6] == vec[1][2]) {
			rightSwap2(vec, 2);
		}
		else if (vec[0][2] == vec[1][6]) {
			rightSwap2(vec, 1);
		}
		else {
			rightSwap2(vec, 0);
		}
	}
	else if (num == 3) {

		if (vec[2][2] == vec[3][6] && vec[2][6] == vec[1][2]) {
			int x = vec[2].back();
			vec[2].pop_back();
			vec[2].push_front(x);
		}
		else if (vec[2][6] == vec[1][2]) {
			int x = vec[2].back();
			vec[2].pop_back();
			vec[2].push_front(x);

			x = vec[3].front();
			vec[3].pop_front();
			vec[3].push_back(x);
		}
		else if (vec[2][2] == vec[3][6]) {

			if (vec[1][6] == vec[0][2]) {
				int x = vec[2].back();
				vec[2].pop_back();
				vec[2].push_front(x);

				x = vec[1].front();
				vec[1].pop_front();
				vec[1].push_back(x);
			}
			else {
				int x = vec[2].back();
				vec[2].pop_back();
				vec[2].push_front(x);

				x = vec[1].front();
				vec[1].pop_front();
				vec[1].push_back(x);

				x = vec[0].back();
				vec[0].pop_back();
				vec[0].push_front(x);
			}
		}
		else {
			if (vec[1][6] == vec[0][2]) {
				int x = vec[2].back();
				vec[2].pop_back();
				vec[2].push_front(x);

				x = vec[3].front();
				vec[3].pop_front();
				vec[3].push_back(x);

				x = vec[1].front();
				vec[1].pop_front();
				vec[1].push_back(x);
			}
			else {
				int x = vec[2].back();
				vec[2].pop_back();
				vec[2].push_front(x);

				x = vec[3].front();
				vec[3].pop_front();
				vec[3].push_back(x);

				x = vec[1].front();
				vec[1].pop_front();
				vec[1].push_back(x);

				x = vec[0].back();
				vec[0].pop_back();
				vec[0].push_front(x);
			}
		}
	}
	else {//gear 2
		if (vec[1][2] == vec[2][6] && vec[1][6] == vec[0][2]) {
			int x = vec[1].back();
			vec[1].pop_back();
			vec[1].push_front(x);
		}
		else if (vec[1][2] == vec[2][6]) {
			int x = vec[1].back();
			vec[1].pop_back();
			vec[1].push_front(x);

			x = vec[0].front();
			vec[0].pop_front();
			vec[0].push_back(x);
		}
		else if (vec[1][6] == vec[0][2]) {

			if (vec[2][2] == vec[3][6]) {
				int x = vec[1].back();
				vec[1].pop_back();
				vec[1].push_front(x);

				x = vec[2].front();
				vec[2].pop_front();
				vec[2].push_back(x);
			}
			else {
				int x = vec[1].back();
				vec[1].pop_back();
				vec[1].push_front(x);

				x = vec[2].front();
				vec[2].pop_front();
				vec[2].push_back(x);

				x = vec[3].back();
				vec[3].pop_back();
				vec[3].push_front(x);
			}
		}
		else {
			if (vec[2][2] == vec[3][6]) {
				int x = vec[1].back();
				vec[1].pop_back();
				vec[1].push_front(x);

				x = vec[0].front();
				vec[0].pop_front();
				vec[0].push_back(x);

				x = vec[2].front();
				vec[2].pop_front();
				vec[2].push_back(x);
			}
			else {
				int x = vec[1].back();
				vec[1].pop_back();
				vec[1].push_front(x);

				x = vec[0].front();
				vec[0].pop_front();
				vec[0].push_back(x);

				x = vec[2].front();
				vec[2].pop_front();
				vec[2].push_back(x);

				x = vec[3].back();
				vec[3].pop_back();
				vec[3].push_front(x);
			}
		}
	}

	return 0;
}

int clockleft(deque<int> vec[4], int num) {
	
	if (num == 1) {

		if (vec[0][2] == vec[1][6])
		{
			int x = vec[0].front();
			vec[0].pop_front();
			vec[0].push_back(x);
		}
		else if (vec[1][2] == vec[2][6]) {
			int x = vec[0].front();
			vec[0].pop_front();
			vec[0].push_back(x);

			x = vec[1].back();
			vec[1].pop_back();
			vec[1].push_front(x);

		}
		else if (vec[2][2] == vec[3][6]) {
			int x = vec[0].front();
			vec[0].pop_front();
			vec[0].push_back(x);

			x = vec[1].back();
			vec[1].pop_back();
			vec[1].push_front(x);

			x = vec[2].front();
			vec[2].pop_front();
			vec[2].push_back(x);
		}
		else {
			int x = vec[0].front();
			vec[0].pop_front();
			vec[0].push_back(x);

			x = vec[1].back();
			vec[1].pop_back();
			vec[1].push_front(x);

			x = vec[2].front();
			vec[2].pop_front();
			vec[2].push_back(x);

			x = vec[3].back();
			vec[3].pop_back();
			vec[3].push_front(x);
		}

	}

	else if (num == 4) {

		if (vec[2][2] == vec[3][6])
		{
			int x = vec[3].front();
			vec[3].pop_front();
			vec[3].push_back(x);
		}
		else if (vec[2][6] == vec[1][2]) {
			int x = vec[3].front();
			vec[3].pop_front();
			vec[3].push_back(x);

			x = vec[2].back();
			vec[2].pop_back();
			vec[2].push_front(x);
		}
		else if (vec[0][2] == vec[1][6]) {
			int x = vec[3].front();
			vec[3].pop_front();
			vec[3].push_back(x);

			x = vec[2].back();
			vec[2].pop_back();
			vec[2].push_front(x);

			x = vec[1].front();
			vec[1].pop_front();
			vec[1].push_back(x);
		}
		else {
			int x = vec[3].front();
			vec[3].pop_front();
			vec[3].push_back(x);

			x = vec[2].back();
			vec[2].pop_back();
			vec[2].push_front(x);

			x = vec[1].front();
			vec[1].pop_front();
			vec[1].push_back(x);

			x = vec[0].back();
			vec[0].pop_back();
			vec[0].push_front(x);
		}
	}

	else if (num == 3) {

		if (vec[2][2] == vec[3][6] && vec[2][6] == vec[1][2]) {
			int x = vec[2].front();
			vec[2].pop_front();
			vec[2].push_back(x);
		}
		else if (vec[2][6] == vec[1][2]) {
			int x = vec[2].front();
			vec[2].pop_front();
			vec[2].push_back(x);

			x = vec[3].back();
			vec[3].pop_back();
			vec[3].push_front(x);
		}
		else if (vec[2][2] == vec[3][6]) {

			if (vec[1][6] == vec[0][2]) {
				int x = vec[2].front();
				vec[2].pop_front();
				vec[2].push_back(x);

				x = vec[1].back();
				vec[1].pop_back();
				vec[1].push_front(x);
			}
			else {
				int x = vec[2].front();
				vec[2].pop_front();
				vec[2].push_back(x);

				x = vec[1].back();
				vec[1].pop_back();
				vec[1].push_front(x);

				x = vec[0].front();
				vec[0].pop_front();
				vec[0].push_back(x);
			}
		}
		else {
			if (vec[1][6] == vec[0][2]) {
				int x = vec[2].front();
				vec[2].pop_front();
				vec[2].push_back(x);

				x = vec[3].back();
				vec[3].pop_back();
				vec[3].push_front(x);

				x = vec[1].back();
				vec[1].pop_back();
				vec[1].push_front(x);
			}
			else {
				int x = vec[2].front();
				vec[2].pop_front();
				vec[2].push_back(x);

				x = vec[3].back();
				vec[3].pop_back();
				vec[3].push_front(x);

				x = vec[1].back();
				vec[1].pop_back();
				vec[1].push_front(x);

				x = vec[0].front();
				vec[0].pop_front();
				vec[0].push_back(x);
			}
		}
	}
	else {//gear 2
		if (vec[1][2] == vec[2][6] && vec[1][6] == vec[0][2]) {
			int x = vec[1].front();
			vec[1].pop_front();
			vec[1].push_back(x);
		}
		else if (vec[1][2] == vec[2][6]) {
			int x = vec[1].front();
			vec[1].pop_front();
			vec[1].push_back(x);

			x = vec[0].back();
			vec[0].pop_back();
			vec[0].push_front(x);
		}
		else if (vec[1][6] == vec[0][2]) {

			if (vec[2][2] == vec[3][6]) {
				int x = vec[1].front();
				vec[1].pop_front();
				vec[1].push_back(x);

				x = vec[2].back();
				vec[2].pop_back();
				vec[2].push_front(x);
			}
			else {
				int x = vec[1].front();
				vec[1].pop_front();
				vec[1].push_back(x);

				x = vec[2].back();
				vec[2].pop_back();
				vec[2].push_front(x);

				x = vec[3].front();
				vec[3].pop_front();
				vec[3].push_back(x);
			}
		}
		else {

			if (vec[2][2] == vec[3][6]) {
				int x = vec[1].front();
				vec[1].pop_front();
				vec[1].push_back(x);

				x = vec[0].back();
				vec[0].pop_back();
				vec[0].push_front(x);

				x = vec[2].back();
				vec[2].pop_back();
				vec[2].push_front(x);
			}
			else {
				int x = vec[1].front();
				vec[1].pop_front();
				vec[1].push_back(x);

				x = vec[0].back();
				vec[0].pop_back();
				vec[0].push_front(x);

				x = vec[2].back();
				vec[2].pop_back();
				vec[2].push_front(x);

				x = vec[3].front();
				vec[3].pop_front();
				vec[3].push_back(x);
			}
		}
	}

	return 0;
}

int main() {
	deque<int> gear[4];
	int testcase, gearnum, velo;
	const int forward_velocity = 1, end_velocity=-1;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &velo);
			gear[i].push_back(velo);
		}
	}

	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> gearnum >> velo;

		if (velo == 1) {
			clockright(gear, gearnum);
		}
		else {
			clockleft(gear, gearnum);
		}
	}

	int sum = 0;
	if (gear[0][0] == 1) sum++;
	if (gear[1][0] == 1) sum+=2;
	if (gear[2][0] == 1) sum+=4;
	if (gear[3][0] == 1) sum+=8;

	cout << sum;
}