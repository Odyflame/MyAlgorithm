
/*2015112119 by ������*/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {

	int Man, Woman, InternShip, Team = 0, extra = 0;

	cin >> Woman >> Man >> InternShip;

	if (Woman >= Man) {//���ڰ� �� �������

		for (int i = 1; i <= Man; i++) {
			if (i * 2 <= Woman) Team++;
			else break;
		}

		extra = Woman + Man - Team * 3;//���⼭ �� �ؾ��ҵ��ϴ�

		if (extra < 0) extra = 0;

		if (Team == 0) cout << Team;//Team�� 0�ϰ��
		else {
			InternShip -= extra;//���� �ο� ����
			
			if (InternShip > 0) {//���� �ο����� ���Ͻ��� �� �ο��� ���� ���
				Team -= InternShip / 3;
				if (InternShip % 3 > 0) Team--;
			}

			if (Team > 0) cout << Team;
			else cout << 0;
		}
	}
	else {//���ڰ� �� �������

		int tempMan = Man;

		for (int i = 2; i <= Woman; i+=2) {
			if (i <= Man) Team++;
			else break;
		}
		
		extra = tempMan - Team;

		if (Team == 0) cout << 0;
		else {
			InternShip -= extra;//���� �ο� ����
			
			if (InternShip > 0) {//���� �ο����� ���Ͻ��� �� �ο��� ���� ���
				
				Team -= InternShip / 3;
				if (InternShip % 3 > 0) Team--;

			}

			if (Team > 0) cout << Team;
			else cout << 0;
		}
	}
}