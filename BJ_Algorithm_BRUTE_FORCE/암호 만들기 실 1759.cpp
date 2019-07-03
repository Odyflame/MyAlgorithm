//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//vector<char> v(16);
//vector<char> v2(1000000);
//
//int cnt = 0;
//
//void dfs(int a, int b, int n, int m) {
//	if (b==n) {
//		if (find(v2.begin(), v2.end(), 'a') != v2.end() || find(v2.begin(), v2.end(), 'i') != v2.end() || find(v2.begin(), v2.end(), 'e') != v2.end() || find(v2.begin(), v2.end(), 'o') != v2.end() || find(v2.begin(), v2.end(), 'u') != v2.end())
//		{
//			if (find(v2.begin(), v2.end(), 'a') != v2.end()) cnt++;
//			if (find(v2.begin(), v2.end(), 'i') != v2.end()) cnt++;
//			if (find(v2.begin(), v2.end(), 'e') != v2.end()) cnt++;
//			if (find(v2.begin(), v2.end(), 'o') != v2.end()) cnt++;
//			if (find(v2.begin(), v2.end(), 'u') != v2.end()) cnt++;
//
//			if (cnt < 3) {
//				//for (int i = 0; i < n; i++) cout << v2[i];
//				
//				cout << endl;
//			}
//			cnt = 0;
//		}
//	}
//
//	// 1. _start_idx 의 범위 초과시 종료
//	// 2. 필요한 숫자의 개수가 남은 숫자의 개수보다 크면 끝내기
//
//	for (int i = a; i < m; i++) {
//		v2[b] = v[i];
//		dfs(i+1, b+1, n, m);
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	int n, m;
//	cin >> n >> m;
//
//	v.resize(m);
//
//	for (int i = 0; i < m; i++) cin >> v[i];
//	sort(v.begin(), v.end());
//	dfs(0, 0, n, m);
//
//	return 0;
//}





#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int check[27];
int l, c;

void go(int now, int lo, int mo, int ja) {
	if (lo == l + 1 && ja > 1 && mo > 0) {
		for (int i = 0; i < 27; i++) {
			if (check[i] == 1)
				printf("%c", i + 'a');
		}puts("");
		return;
	}
	for (int i = now; i < v.size(); i++) {
		if (check[v[i]] == 0) {
			check[v[i]] = 1;
			if (v[i] == 0 || v[i] == 4 || v[i] == 8 || v[i] == 14 || v[i] == 20) go(i, lo + 1, mo + 1, ja);
			else go(i, lo + 1, mo, ja + 1);
			check[v[i]] = 0;
		}
	}
}

int main(void) {
	scanf("%d %d", &l, &c);
	for (int i = 0; i < c; i++) {
		char num;
		scanf(" %c", &num);
		v.push_back(num - 'a');
	}
	sort(v.begin(), v.end());
	go(0, 1, 0, 0);
	return 0;
}


//https://www.acmicpc.net/problem/11970
//http://1ilsang.blog.me/221328922544