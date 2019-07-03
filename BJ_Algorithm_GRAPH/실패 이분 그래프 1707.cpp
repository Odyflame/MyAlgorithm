#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int k, v, e;

vector<int> arr2[20003];

int colors[20003];
int check = -1;
int from, to;

queue<int> arr3;

int anscheck = -1;

void BFS(int idx)
{
	arr3.push(idx);
	
	colors[idx] = check;
	check *= -1;
	

	while (!arr3.empty())
	{
		idx = arr3.front();
		arr3.pop();
		
		if (colors[idx]!=0) continue;

		for (int i = 0; i < (int)arr2[idx].size(); i++) {
			
			//다음 노드가 존재하고 그 노드가 색깔이 없을 때
			if (arr2[idx][i] && colors[arr2[idx][i]] == 0)
			{
				//색깔을 칠해준다.
				colors[arr2[idx][i]] = check;
				arr3.push(arr2[idx][i]);
			}

			//노드에 색깔이 존재하고 노드의 색깔이 그 다음 노드와 같을 때 이분그래프가 아니다.
			if (colors[arr2[idx][i]] != 0 && colors[arr2[idx][i]] == colors[idx]) {
			
				anscheck = 2;
				return;
			}

		}
		check *= -1;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;

	for (int b = 0; b < k; b++) {
		cin >> v >> e;

		//색깔과 값이 저장된 벡터 초기화
		//memset(colors, 0, sizeof(colors));
		for (int i = 1; i <= v; i++) colors[i] = 0;
		for (int i = 1; i <= v; i++) arr2[i].clear();

		for (int i = 0; i < e; i++) {
			cin >> from >> to;

			arr2[from].push_back(to);
			arr2[to].push_back(from);

		}

		for (int i = 1; i <= v; i++) {
			BFS(i); 
			while (!arr3.empty()) {
				arr3.pop();
			}
		}

		//이분 그래프가 아닐경우
		if(anscheck==2) cout << "NO" << '\n';
		else cout << "YES" << '\n';

		anscheck = -1;
	}
}