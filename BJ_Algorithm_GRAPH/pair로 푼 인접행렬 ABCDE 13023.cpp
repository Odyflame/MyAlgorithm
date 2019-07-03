// ���� - ABCDE (13023��)
// : �׷������� A-B-C-D-E �� �մ� ���� �����Ѱ�?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ���
bool matrix[2000][2000];
// ���� ����Ʈ
vector<int> graph[2000];
// ���� ����Ʈ
vector<pair<int, int>> edges;

int main() {
	// ��� �� & ���� �� �Է� �ޱ�
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		// ���� ��Ŀ� ����
		matrix[from][to] = matrix[to][from] = true;

		// ���� ����Ʈ�� ����
		graph[from].push_back(to);
		graph[to].push_back(from);

		// ���� ����Ʈ�� ����
		edges.push_back({ from, to });
		edges.push_back({ to, from });
	}

	// �׷������� ��� ����� ���� Ž���ϸ� ������ A-B-C-D-E ������ �����ϴ��� Ȯ��
	m *= 2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			// ���� ����Ʈ���� A -> B ����
			int A = edges[i].first;
			int B = edges[i].second;
			// ���� ����Ʈ���� A -> B ����
			int C = edges[j].first;
			int D = edges[j].second;
			// ��ġ�� �� �����ϸ� ��ŵ
			if (A == B || A == C || A == D || B == C || B == D || C == D) {
				continue;
			}
			// ���� ��Ŀ��� B->C ������� ������ ��ŵ
			if (!matrix[B][C]) continue;

			// ���� ����Ʈ���� D->E ã��
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