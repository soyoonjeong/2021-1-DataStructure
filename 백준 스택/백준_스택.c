#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
//스택실습문제 1번과 동일->연결리스트로 구현
typedef struct node {
	int elem;
	struct node* next;
}NODE;
NODE* getnode() {
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn->next = NULL;
	return nn;
}
void push(NODE** stack,int e) {
	NODE* nn = getnode();
	nn->elem = e;
	nn->next = *stack;
	*stack = nn;
}
int pop(NODE** stack) {
	if (*stack == NULL)
		return -1;
	NODE* temp = *stack;
	*stack = (*stack)->next;
	return temp->elem;
}
int size(NODE* stack) {
	int n = 0;
	for (NODE* p = stack; p; p = p->next)
		n++;
	return n;
}
int top(NODE* stack) {
	if (stack == NULL)
		return -1;
	return stack->elem;
}
int main() {
	NODE* stack = NULL;
	char select[6];
	int M, e;
	scanf("%d", &M);
	getchar();
	for (int i = 0; i < M; i++) {
		scanf("%s", select);
		if (strcmp(select, "push") == 0) {
			scanf("%d", &e);
			push(&stack, e);
		}
		else if (strcmp(select, "pop") == 0)
			printf("%d\n", pop(&stack));
		else if (strcmp(select, "size") == 0)
			printf("%d\n", size(stack));
		else if (strcmp(select, "empty") == 0)
			printf("%d\n", stack==NULL);
		else if (strcmp(select, "top") == 0)
			printf("%d\n", top(stack));
	}
}