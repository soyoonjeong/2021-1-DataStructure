#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void push(int* stack, int* top, int n) {
	(*top)++;
	stack[*top] = n;
}
int sum(int* stack, int top) {
	int result = 0;
	for (int i = 0; i <= top; i++)
		result += stack[i];
	return result;
}	

int main() {
	int k, n, * stack = NULL, top = -1;
	scanf("%d", &k);
	stack = (int*)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		if (n != 0)
			push(stack, &top, n);
		else
			top--;
	}
	printf("%d", sum(stack, top));
}