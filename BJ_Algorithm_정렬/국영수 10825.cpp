//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <set>
//
//using namespace std;
//
//class Student {
//public:
//	string name;
//	int korean, english, math;
//	Student(string noname = "noname", int a = 0, int b = 0, int c = 0)
//		: name(noname), korean(a), english(b), math(c) {}
//
//	void print() {
//		cout << name << " " << korean << " " << english << " " << math << endl;;
//	}
//};
//
//bool comparision(Student a, Student b) {
//	if (a.korean > b.korean) {//국어가 큰경우 바꿈
//		return true;
//	}
//	else if (a.korean == b.korean) {
//		if (a.english < b.english) {//영어가 작은경우 바꿈
//			return true;
//		}
//		else if (a.english == b.english) {
//			if (a.math > b.math) {//수학이 큰경우
//				return true;
//			}
//			else if (a.math == b.math) {
//				return a.name < b.name;//문자열 사전순 바꿈
//			}
//			else return false;
//		}
//		else return false;
//	}
//	else return false;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	Student *student = new Student[100000];
//	int n, korean, english, math;
//	string stu_name;
//	cin >> n;
//
//	set<Student> qu;
//
//	for (int i = 0; i < n; i++) {
//		cin >> stu_name >> korean >> english >> math;
//
//		Student temp(stu_name, korean, english, math);
//		
//		qu.insert(temp);
//
//		set<Student>::iterator iter;	
//
//		for (auto ele = qu.begin(); ele != qu.end(); ele++) {
//			iter = qu.find(temp);
//			if(comparision(*iter, ))
//		}
//	}
//	
//}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int korean, english, math;
	Student(string noname = "noname", int a = 0, int b = 0, int c = 0)
		: name(noname), korean(a), english(b), math(c) {}

	void print() {
		cout << name << " " << korean << " " << english << " " << math << endl;;
	}
};

bool comparision(Student a, Student b) {
	if (a.korean > b.korean) {//국어가 큰경우 바꿈
		return true;
	}
	else if (a.korean == b.korean) {
		if (a.english < b.english) {//영어가 작은경우 바꿈
			return true;
		}
		else if (a.english == b.english) {
			if (a.math > b.math) {//수학이 큰경우
				return true;
			}
			else if (a.math == b.math) {
				return a.name < b.name;//문자열 사전순 바꿈
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Student *student = new Student[100000];
	int n, korean, english, math;
	string stu_name;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> stu_name >> korean >> english >> math;

		Student temp(stu_name, korean, english, math);

		student[i] = temp;

		for (int j = 0; j < i; j++) {
			if (comparision(student[i], student[j])) {
				Student temp = student[i];
				student[i] = student[j];
				student[j] = temp;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) cout << student[i].name << '\n';
}