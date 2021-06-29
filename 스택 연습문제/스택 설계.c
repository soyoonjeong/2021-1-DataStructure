#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//단일연결리스트로 스택 구현
typedef struct stack {
	int elem;
	struct stack* next;
}STACK;

void push(STACK* top,int newInt) {
	STACK* n = (STACK*)malloc(sizeof(STACK));
	char new_stack[101], e;
	int new_top = -1;
	n->elem = newInt;
	if (top != NULL) {
		while (top->elem < newInt) {
			e = pop(top);
			new_stack[++new_top] = e;
		}
	}
	
	n->next = top;
	top = n;
}
int pop(STACK* top) {
	STACK *del = top;
	int delElem = top->elem;
	top = top->next;
	free(del);
	return delElem;
}
void print(STACK* top) {
	STACK* p = top;
	while (p != NULL) {
		printf("%d", p->elem);
		p = p->next;
	}
	printf("\n");
}
int findmin(STACK* top) {
	int min = pop(top), e;
	while (top != NULL) {
		e = pop(top);
		if (min > e)
			min = e;
	}
	return e;
}
int main() {
	STACK* top = NULL;
	char command[5];
	int pushInt;
	while (1) {
		scanf("%s", command);
		if (strcmp(command, "PUSH") == 0) {
			getchar();
			scanf("%d", &pushInt);
			push(top, pushInt);
		}
		else if (strcmp(command, "POP") == 0) {
			pop(top);
		}
		else if (strcmp(command, "PRINT") == 0) {
			print(top);
		}
		else if (strcmp(command, "MIN") == 0) {

		}
	}
}