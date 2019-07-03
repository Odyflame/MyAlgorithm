/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

list<int> linked_list;
int Count = 0;

int main() {

	int n, m, from_node, to_node;
	char order;

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) linked_list.push_back(i+1);

	for (int i = 0; i < m; i++) {
		scanf("%c%d%d", &order, &from_node, &to_node);
		
		for (list<int>::iterator iter = linked_list.begin(); iter != linked_list.end(); iter++) {
			if (*iter == from_node) {
				linked_list.erase(iter); break;
			}
		}

		if (order == 'A') {

			for (list<int>::iterator iter = linked_list.begin(); iter != linked_list.end(); iter++) {
				if (*iter == to_node) {
					linked_list.insert(iter, from_node);
				}
			}
		}
		else if (order == 'B') {
			for (list<int>::iterator iter = linked_list.begin(); iter != linked_list.end(); iter++) {
				if (*iter == to_node) {
					iter++;
					linked_list.insert(iter, from_node);
				}
			}
		}
	}


}