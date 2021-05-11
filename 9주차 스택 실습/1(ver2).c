#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void print(char* stack, int t) {
	for (int i = t; i >= 0; i--)
		printf("%c", stack[i]);
	printf("\n");
}
int push(char* stack, char data, int t, int n) {
	if (t == n - 1) {
		printf("Stack FULL\n");
		return n - 1;
	}
	stack[t + 1] = data;
	//print(arr, t + 1);
	return t + 1;
}
char pop(char* stack, int* t) {
	if (*t == -1) {
		printf("Stack Empty\n");
		return 'a';
	}
	(*t)--;
	return stack[*t + 1];
}
void peek(char* stack, int t) {
	if (t == -1)
		printf("Stack Empty\n");
	else
		printf("%c\n", stack[t]);
}
void dup(char* stack, int* t, int n) {
	if (*t == n - 1)
		printf("Stack FULL\n");
	else {
		char e = pop(stack, t);
		*t = push(stack, e, *t, n);
		*t = push(stack, e, *t, n);
	}
}
int uprotate(char* stack, int *top, int r, int n) {
	if (r > *top + 1)
		return 0;
	char topelem, * arr, e;
	arr = (char*)malloc((r-1) * sizeof(char));
	topelem = pop(stack, top);
	for (int i = 0; i < r - 1; i++) 
		arr[i] = pop(stack, top);
	push(stack, topelem, *top, n);
	for (int i = r-2; i>=0; i++) {
		push(stack, arr[i], *top, n);
	}
	print(stack, *top);
	free(arr);
	return top;
}
int downrotate(char* stack, int *top, int r) {
	if (r > *top + 1)
		return 0;
	int new_top = -1;
	char downelem, * newstack, e;
	newstack = (char*)malloc(r * sizeof(char));
	for (int i = 0; i < r - 1; i++) {
		e = pop(stack, top);
		push(newstack, e, new_top, r);
	}
	//print(newstack, new_top);
	downelem = pop(stack, top);
	for (int i = 0; i < r - 1; i++) {
		e = pop(newstack, &new_top);
		push(stack, e, *top, r);
	}
	push(stack, downelem, *top, r);
	return downelem;
}

int main() {
	int n, m, top = -1, r;
	char* stack = NULL, select[11], data;
	scanf("%d", &n);
	stack = (char*)malloc(n * sizeof(char));
	scanf("%d", &m);
	getchar();
	for (int i = 0; i < m; i++) {
		scanf("%s", select);
		if (strcmp(select, "PUSH") == 0) {
			getchar();
			scanf("%c", &data);
			top = push(stack, data, top, n);
		}
		else if (strcmp(select, "POP") == 0)
			pop(stack, &top);
		else if (strcmp(select, "PEEK") == 0)
			peek(stack, top);
		else if (strcmp(select, "DUP") == 0)
			dup(stack, &top, n);
		else if (strcmp(select, "UpR") == 0) {
			scanf("%d", &r);
			uprotate(stack, &top, r,n);
		}
		else if (strcmp(select, "DownR") == 0) {
			scanf("%d", &r);
			downrotate(stack, &top, r,n);
		}
		else if (strcmp(select, "PRINT") == 0)
			print(stack, top);
	}
}