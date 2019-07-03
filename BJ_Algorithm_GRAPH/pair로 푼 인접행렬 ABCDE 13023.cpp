// 백준 - ABCDE (13023번)
// : 그래프에서 A-B-C-D-E 를 잇는 것이 가능한가?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 인접 행렬
bool matrix[2000][2000];
// 인접 리스트
vector<int> graph[2000];
// 간선 리스트
vector<pair<int, int>> edges;

int main() {
	// 사람 수 & 관계 수 입력 받기
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		// 인접 행렬에 삽입
		matrix[from][to] = matrix[to][from] = true;

		// 인접 리스트에 삽입
		graph[from].push_back(to);
		graph[to].push_back(from);

		// 간선 리스트에 삽입
		edges.push_back({ from, to });
		edges.push_back({ to, from });
	}

	// 그래프에서 모든 경우의 수를 탐색하며 가능한 A-B-C-D-E 연결이 존재하는지 확인
	m *= 2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			// 간선 리스트에서 A -> B 지정
			int A = edges[i].first;
			int B = edges[i].second;
			// 간선 리스트에서 A -> B 지정
			int C = edges[j].first;
			int D = edges[j].second;
			// 겹치는 것 존재하면 스킵
			if (A == B || A == C || A == D || B == C || B == D || C == D) {
				continue;
			}
			// 인접 행렬에서 B->C 연결되지 않으면 스킵
			if (!matrix[B][C]) continue;

			// 인접 리스트에서 D->E 찾기
			for (int E : graph[D]) {
				if (A == E || B == E || C == E || D == E) {
					continue;
				}
				cout << 1 << '\n';
				return 0;
			}
		}
	}
	cout << 0 << '\n';
	return 0;
}

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector<vector<int> > v(3001, vector<int>(0));
int N, M, x, y, visit[3001], flag;
int dfs(int x, int cnt)
{
	if (cnt >= 5)
	{
		flag = 1;
		return 0;
	}
	visit[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
	{
		if (!visit[v[x][i]])
			dfs(v[x][i], cnt + 1);
	}
	visit[x] = 0;
}
int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 0; i < N; i++)
	{
		memset(visit, 0, sizeof(visit));

		dfs(i, 1);

		if (flag)
		{
			cout << "1\n";
			return 0;
		}
	}
	cout << 0;
}