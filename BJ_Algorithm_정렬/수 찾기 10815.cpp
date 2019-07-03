/*
*2015112119 by ������
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

int stack[500001];
int main() {
	int N, Value, N2, Check_Value;
	scanf("%d", &N);//���� ī���� ����

	for (int i = 0; i < N; i++) {
		scanf("%d", &Value);//���� ī�� �� �Է�
		stack[i] = Value;
	}
	sort(stack, stack + N);
	scanf("%d", &N2);//���� ī�尡 �ִ��� Ȯ���� Ƚ��

	for (int i = 0; i < N2; i++) {
		int right = N - 1, left = 0, mid = (right + left) / 2;
		scanf("%d", &Check_Value);//������ ���� ī��
		while (true) {
			if (Check_Value == stack[mid]) {
				printf("1 ");
				break;
			}
			else if (Check_Value > stack[mid]) {
				if (mid == left && Check_Value != stack[right]) {
					printf("0 ");
					break;
				}
				else if (mid == left && Check_Value == stack[right]) {
					printf("1 ");
					break;
				}
				left = mid;
				mid = (left + right) / 2;
			}
			else if (Check_Value < stack[mid]) {
				if (mid == left && Check_Value != stack[right]) {
					printf("0 ");
					break;
				}
				else if (mid == left && Check_Value == stack[right]) {
					printf("1 ");
					break;
				}
				right = mid;
				mid = (left + right) / 2;
			}
		}
	}
	printf("\n");
}