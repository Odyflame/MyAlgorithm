
/*2015112119 by 이현재*/

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

	if (Woman >= Man) {//여자가 더 많은경우

		for (int i = 1; i <= Man; i++) {
			if (i * 2 < Woman) {//Woman의 수가 부족
				Team++;
			}
			else break;
		}

		InternTeam = Woman + Man - Team * 3;//여기서 더 해야할듯하다

		if (Team == 0) cout << Team;//Team이 0일경우
		else {
			if (Internship > InternTeam) {//남는 인원보다 인턴쉽게 갈 인원이 많은 경우
				if ((Internship - InternTeam) / 3 > 0)
					Team -= (Internship - InternTeam) / 3;
				else Team -= 1;
			}

			if (Team > 0) cout << Team;
			else cout << 0;
		}
	}
	else {//남자가 더 많은경우
		Team = Woman / 2;
		InternTeam = Man - Team;

		if (Team == 0) cout << 0;
		else {
			if (InternShip > InternTeam) {//남는 인원보다 인턴쉽게 갈 인원이 많은 경우
				Team -= Internship - InternTeam;
			}

			cout << Team;
		}
	}
}