
/*2015112119 by 이현재*/

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

	if (Woman >= Man) {//여자가 더 많은경우

		for (int i = 1; i <= Man; i++) {
			if (i * 2 <= Woman) Team++;
			else break;
		}

		extra = Woman + Man - Team * 3;//여기서 더 해야할듯하다

		if (extra < 0) extra = 0;

		if (Team == 0) cout << Team;//Team이 0일경우
		else {
			InternShip -= extra;//남는 인원 제외
			
			if (InternShip > 0) {//남는 인원보다 인턴쉽게 갈 인원이 많은 경우
				Team -= InternShip / 3;
				if (InternShip % 3 > 0) Team--;
			}

			if (Team > 0) cout << Team;
			else cout << 0;
		}
	}
	else {//남자가 더 많은경우

		int tempMan = Man;

		for (int i = 2; i <= Woman; i+=2) {
			if (i <= Man) Team++;
			else break;
		}
		
		extra = tempMan - Team;

		if (Team == 0) cout << 0;
		else {
			InternShip -= extra;//남는 인원 제외
			
			if (InternShip > 0) {//남는 인원보다 인턴쉽게 갈 인원이 많은 경우
				
				Team -= InternShip / 3;
				if (InternShip % 3 > 0) Team--;

			}

			if (Team > 0) cout << Team;
			else cout << 0;
		}
	}
}