#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define itemType treeNode *

void traverse(struct treeNode *t);
void visit(struct treeNode *t);

struct treeNode {
	char info;
	struct treeNode *l, *r;
};
struct treeNode *x, *z;

class Stack
{
public:
	Stack(int max = 100) {
		stack = new itemType[max];
		p = 0;
	};
	~Stack() {
		//lab#2�� ������ �ۼ� 
	};
	inline void push(itemType v) {//stackü ���� �����Ѵ�.
		//lab#2�� ������ �ۼ� 
		stack[p++] = v;//������ top�� p�̴� �ű⿡ �޾Ƶ��� ���� �����ϰ� p�� 1�� ������Ų��. 
	};
	inline itemType pop() {
		//lab#2�� ������ �ۼ� 
		p--;//top�� 1���ҽ��� ���� ���� ���� ����Ų��.
		itemType k = stack[p];
		stack[p] = NULL;//���־����� �ű⿡ �ִ� ���� NULL�� �ȴ�.

		return k;//�� �� ����
	};
	inline int empty() {
		//lab#2�� ������ �ۼ� 
		if (p == 0) return 1;//top�� 0�̸� stack�� �ƹ��͵� ����
	}
private:
	itemType *stack;
	int p;
};

int main()
{
	char c; Stack stack(50);
	z = new treeNode;//���ο� ��� ����
	z->l = z;
	z->r = z;
	while ((c = cin.get()) != '\n')
	{
		while (c == ' ') cin.get(c);
		x = new treeNode;
		x->info = c; x->l = z; x->r = z;
		if (c == '+' || c == '*' || c == '-') {
			x->r = stack.pop();//�����ڰ� ������ �����ڿ� ����Ǿ��ִ� ������ �˻��Ѵ�.
			x->l = stack.pop();
		}
		stack.push(x);//���ÿ� ����
	}
	traverse(stack.pop());//���� Ž��
	cout << endl;
	return 0;
}

void visit(struct treeNode *t)
{
	cout << t->info << " ";
}

void traverse(struct treeNode *t)
{
	if (t != z)
	{
		traverse(t->l);//���Ž��
		visit(t);//info ���
		traverse(t->r);
	}
}
