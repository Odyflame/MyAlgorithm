
/*2015112119 by ������*/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	
	int Man, Woman, InternShip, Team = 0, InternTeam = 0;

	cin >> Woman >> man >> InternShip;

	if (Woman >= Man) {//���ڰ� �� �������

		for (int i = 1; i <= Man; i++) {
			if (i * 2 < Woman) {//Woman�� ���� ����
				Team++;
			}
			else break;
		}

		InternTeam = Woman + Man - Team * 3;//���⼭ �� �ؾ��ҵ��ϴ�

		if (Team == 0) cout << Team;//Team�� 0�ϰ��
		else {
			if (Internship > InternTeam) {//���� �ο����� ���Ͻ��� �� �ο��� ���� ���
				if ((Internship - InternTeam) / 3 > 0)
					Team -= (Internship - InternTeam) / 3;
				else Team -= 1;
			}

			if (Team > 0) cout << Team;
			else cout << 0;
		}
	}
	else {//���ڰ� �� �������
		Team = Woman / 2;
		InternTeam = Man - Team;

		if (Team == 0) cout << 0;
		else {
			if (InternShip > InternTeam) {//���� �ο����� ���Ͻ��� �� �ο��� ���� ���
				Team -= Internship - InternTeam;
			}

			cout << Team;
		}
	}
}