#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int rank(char c) {
	char oper[6] = "*/+-(";
	int rank[5] = { 2,2,1,1,0 };
	for (int i = 0; i < 5; i++) {
		if (c == oper[i])
			return rank[i];
	}
}
void push(char* stack, int* top, char c) {
	stack[++(*top)] = c;
}
char pop(char* stack, int* top) {
	return stack[(*top)--];
}
void convert(char* str) {
	char stack[101];
	int top = -1;
	for (char* c = str; *c != '\0'; c++) {
		if (*c >= 'A' && *c <= 'Z')
			printf("%c", *c);
		else if (*c == '(')
			push(stack, &top, *c);
		else if (*c == ')') {
			while (stack[top]!='(')
				printf("%c",pop(stack, &top));
			pop(stack, &top);
		}
		else {
			while (top != -1 && rank(*c) <= rank(stack[top]))
				printf("%c", pop(stack, &top));
			push(stack, &top, *c);
		}
 	}
	while (top != -1) {
		printf("%c", pop(stack, &top));
	}
	printf("\n");
}
int main() {
	char str[101];
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		convert(str);
	}
}