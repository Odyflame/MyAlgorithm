#include <iostream>
#include <vector>
using namespace std;

int person, friendship;
int a, b;

bool visited[2002];
vector<int> v[2000];

bool dfs(int start, int depth) {
	if (depth == 4)	return true;

	visited[start] = true;
	
	for (int i = 0; i < v[start].size(); i++) {
			int next = v[start][i];//���� ���
			if (visited[next]) continue;//�湮������ ��ŵ
			if (dfs(next, depth + 1)) return true;//�湮�����ϸ� Ʈ�� ����
	}
	
	visited[start] = false;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> person >> friendship;
	
	for (int i = 0; i < friendship; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for (int i = 0; i < person; i++) {
		if (dfs(i, 0)) {
			cout << "1";
			return 0;
		}
	}cout << "0";
}