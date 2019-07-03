#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Star {
public:
	Star(int hour=0, int minute=0) : hh(hour), mm(minute) {};
	~Star() {};
	int hh, mm;
};

int main() {
	int star1_cycle_hh, star2_cycle_hh, star1_cycle_mm, star2_cycle_mm;
	int a, b;
	int day = 6;
	char slash;
	string dayname[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	scanf("%d%1c%d", &a, &slash, &b);
	
	Star star1(a, b);

	scanf("%2d%1c%2d", &a, &slash, &b);

	Star star2(a, b);

	scanf("%2d%1c%2d", &a, &slash, &b);

	star1_cycle_hh = a; star1_cycle_mm = b;

	scanf("%2d%1c%2d", &a, &slash, &b);

	star2_cycle_hh = a; star2_cycle_mm = b;


}