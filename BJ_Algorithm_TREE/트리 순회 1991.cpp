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
		//lab#2를 참고해 작성 
	};
	inline void push(itemType v) {//stack체 값을 저장한다.
		//lab#2를 참고해 작성 
		stack[p++] = v;//스텍의 top은 p이니 거기에 받아들인 값을 저장하고 p를 1을 증가시킨다. 
	};
	inline itemType pop() {
		//lab#2를 참고해 작성 
		p--;//top을 1감소시켜 값을 빼줄 곳을 가리킨다.
		itemType k = stack[p];
		stack[p] = NULL;//빼주었으니 거기에 있는 값은 NULL이 된다.

		return k;//뺄 값 리턴
	};
	inline int empty() {
		//lab#2를 참고해 작성 
		if (p == 0) return 1;//top이 0이면 stack에 아무것도 없다
	}
private:
	itemType *stack;
	int p;
};

int main()
{
	char c; Stack stack(50);
	z = new treeNode;//새로운 노드 생성
	z->l = z;
	z->r = z;
	while ((c = cin.get()) != '\n')
	{
		while (c == ' ') cin.get(c);
		x = new treeNode;
		x->info = c; x->l = z; x->r = z;
		if (c == '+' || c == '*' || c == '-') {
			x->r = stack.pop();//연산자가 있으면 연산자에 연결되어있는 노드들을 검사한다.
			x->l = stack.pop();
		}
		stack.push(x);//스택에 저장
	}
	traverse(stack.pop());//스택 탐색
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
		traverse(t->l);//재귀탐색
		visit(t);//info 출력
		traverse(t->r);
	}
}
