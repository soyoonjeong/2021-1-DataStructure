#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//사실 무슨 문제인지 잘 모르겠음,,
typedef struct stack {
	int* arr;
	int top;
	int size;
}STACK;
STACK * initstack(int size) {
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	stack->arr = (int*)malloc(size * sizeof(int));
	stack->top = -1;
	stack->size = size;
}
void push(STACK* stack, char e) {
	stack->top++;
	stack->arr[stack->top] = e - '0';

}
int pop(STACK* stack) {
	stack->top--;
	return stack->arr[stack->top + 1];
}
void getBig(STACK* stack) {
	char str[101];
	scanf("%s", str);
	stack = initstack(strlen(str));
	for (int i = strlen(str) - 1; i >= 0; i--)
		push(stack, str[i]);
}
void putBig(STACK* stack) {
	printf("%d", pop(stack));

}
int main() {
	STACK* stack = NULL;
	getBig(stack);
	putBig(stack);
	
}