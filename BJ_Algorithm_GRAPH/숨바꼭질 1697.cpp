#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, k, Count=0, Next;

int visited[200002] = { 0, };
int time[200002] = { 0, };
queue<int> arr;

int bfs(int N, int K) {
	if (N >= K) return n - k;

	arr.push(N);
	visited[N]=1;
	
	while (!arr.empty()) {
		int arr_size = arr.size();
		for (int i = 0; i < arr_size; i++) {
			
				Next = arr.front();
				arr.pop();
				if (Next == K) return Count;
				if (visited[Next - 1] == 0 && Next > 0) {
					arr.push(Next - 1); visited[Next - 1] = 1;
				}
				if (visited[Next + 1] == 0 && Next < 100000) {
					arr.push(Next + 1); visited[Next + 1] = 1;
				}
				if (visited[Next * 2] == 0 && 2 * Next <= 100000) { arr.push(2 * Next); visited[Next * 2] = 1; }
			
		}
		
		Count++;
	}

	return Count;
}

int main() {
	cin >> n >> k;
	cout<< bfs(n, k);
}