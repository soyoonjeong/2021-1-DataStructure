#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void push(int* stack, int* top, char num) {
	stack[++(*top)] = (int)(num - '0');
}
int pop(int* stack, int* top) {
	(*top)--;
	return stack[*top + 1];
}
int evaluate(char* str) {
	int stack[100], top = -1, n;
	for (char* p = str; *p != '\0'; p++) {
		if (*p >= '0' && *p <= '9')
			push(stack, &top, *p);
		else if (*p == '+') {
			n = pop(stack, &top);
			stack[top] = stack[top] + n;
		}
		else if (*p == '-') {
			n = pop(stack, &top);
			stack[top] = stack[top] - n;
		}
		else if (*p == '*') {
			n = pop(stack, &top);
			stack[top] = stack[top] * n;
		}
		else if (*p == '/') {
			n = pop(stack, &top);
			stack[top] = stack[top] / n;
		}

	}
	return stack[0];
}
int main()
{
	char str[101];
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		printf("%d\n", evaluate(str));
	}
}