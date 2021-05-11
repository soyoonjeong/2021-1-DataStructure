#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void print(char* stack, int t) {
	for (int i = t; i >= 0; i--)
		printf("%c", stack[i]);
	//printf("\n");
}
int push(char* stack, char data, int t, int n) {
	if (t == n - 1) {
		printf("Stack FULL\n");
		return n - 1;
	}
	stack[t+1] = data;
	//print(arr, t + 1);
	return t + 1;
}
char pop(char* stack, int *t) {
	if (*t == -1) {
		printf("Stack Empty\n");
		return 'a';
	}
	(*t)--;
	return stack[*t+1];
}
void peek(char* stack, int t) {
	if (t == -1)
		printf("Stack Empty\n");
	else
		printf("%c\n", stack[t]);
}
void dup(char* stack, int *t,int n) {
	if (*t == n - 1) 
		printf("Stack FULL\n");
	else {
		char e = pop(stack, t);
		*t = push(stack, e, *t, n);
		*t = push(stack, e, *t, n);
	}
}
int uprotate(char* stack, int t, int r) {
	if (r > t + 1)
		return 0;
	char top = stack[t];
	for (int i = t - 1; i >= t-r+1; i--)
		stack[i + 1] = stack[i];
	stack[t-r+1] = top;
	return top;
}
int downrotate(char* stack, int t, int r) {
	if (r > t + 1)
		return 0;
	char down = stack[t-r+1];
	for (int i = t-r+2; i <= t; i++)
		stack[i - 1] = stack[i];
	stack[t] = down;
	return down;
}

int main() {
	int n, m, top = -1, r;
	char* stack = NULL, select[11], data;
	scanf("%d", &n);
	stack = (char*)malloc(n * sizeof(char));
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		getchar();
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
			uprotate(stack, top, r);
		}
		else if (strcmp(select, "DownR") == 0) {
			scanf("%d", &r);
			downrotate(stack, top, r);
		}
		else if (strcmp(select, "PRINT") == 0) 
			print(stack, top);
	}
}