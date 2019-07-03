/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>

using namespace std;

int count = 0;

class linked_list {
public:
	int k;

	linked_list(int number=0) 
	: k(number) {
		head = NULL;
	}
	~linked_list() {

	}

	void push(int v) {
		list *temp = new list;

		if (head == NULL) {
			head = temp;
			list *temp2 = new list;
			head->pre = NULL;
			head->next = temp2;
			head->next->key = v;
			head->next->next = NULL;
		}
		else {
			temp = head;
			while (temp->next != NULL) temp = temp->next;
			list *newlist = new list;
			temp->next = newlist;
			temp->next->key = v;
			temp->next->next = NULL;
			
		}
	}

	void swap(int from, int to) {
		list *temp = new list;
		while (temp->next != NULL) {
			temp = temp->next;
		}
	}

	struct list {
		list *pre;
		list *next;
		int key;
	};

	list *head;
};

int main() {
	int n, m, from_node, to_node;
	char order;

	scanf("%d%d", &n, &m);

	//scanf("%d%d", &from_node, &to_node);
	linked_list List;

	for (int i = 0; i < n; i++) List.push(i + 1);
	
	for (int i = 0; i < m; i++) {
		scanf("%c%d%d", &order, &from_node, &to_node);

	}
}