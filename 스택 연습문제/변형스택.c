#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct stack {
	int* arr;
	int top;
	int size;
}STACK;
STACK * getstack(int n) {
	STACK *stack = (STACK*)malloc(sizeof(STACK));
	stack->top = -1;
	stack->size = n;
	stack->arr = (int*)malloc(n * sizeof(int));
	return stack;
}
int pop(STACK* stack) {
	(stack->top)--;
	return stack->arr[stack->top + 1];
}
void popandpush(STACK* popStack, STACK* pushStack) {
	int e = pop(popStack);
	pushStack->top++;
	pushStack->arr[pushStack->top] = e;
}
void fullStackException(STACK *stack) {
	STACK* new_stack = getstack(stack->size);
	while (stack->top > 0) {
		popandpush(stack, new_stack);
	}
	pop(stack);
	while (new_stack->top > -1) {
		popandpush(new_stack, stack);
	}
}
void push(STACK * stack,int e) {
	if (stack->top == stack->size - 1)
		fullStackException(stack);
	stack->top++;
	stack->arr[stack->top] = e;
}
void print(STACK* stack) {
	for (int i = stack->top; i >=0; i--) {
		printf("%d", stack->arr[i]);
	}
	printf("\n");
}
int main() {
	int n, m, push_num;
	char command[5];
	
	scanf("%d", &n);
	STACK* stack = getstack(n);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		getchar();
		scanf("%s", command);
		if (strcmp(command, "PUSH") == 0) {
			scanf("%d", &push_num);
			push(stack, push_num);
		}
		else if (strcmp(command,"POP")==0) {
			pop(stack);
		}
		else {
			print(stack);
		}
	}
	

}