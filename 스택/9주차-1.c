#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int push(char* stack, int* top, int n, char c) {
	if (*top == n - 1) {
		printf("Stack FULL\n");
		return 0;
	}
	*top += 1;
	stack[*top] = c;
}
char pop(char* stack, int* top) {
	if (*top == -1) {
		printf("Stack Empty\n");
		return 0;
	}
	*top -= 1;
	return stack[*top+1];
}
void duplicate(char* stack, int* top, int n) {
	char c = pop(stack, top);
	push(stack, top, n, c);
	push(stack, top, n, c);
}
void move(char* stack1, char* stack2, int* top1, int* top2, int time, int size) {
	int c;
	for (int i = 0; i < time; i++) {
		c = pop(stack1, top1);
		push(stack2, top2, size, c);
	}
}
int uprotate(char* stack, int r, int *top, int n) {
	if (r > *top + 1)
		return 0;
	char* arr = (char*)malloc((r - 1) * sizeof(char));
	int arr_top = -1;
	char up_elem = pop(stack, top);
	move(stack, arr, top, &arr_top, r - 1, r - 1);
	push(stack, top, n, up_elem);
	move(arr, stack, &arr_top, top, r - 1, n);
	free(arr);
}
int downrotate(char* stack, int r, int* top, int n) {
	if (r > *top + 1)
		return 0;
	char* arr = (char*)malloc((r - 1) * sizeof(char));
	int arr_top = -1;
	move(stack, arr, top, &arr_top, r - 1, r - 1);
	char down_elem = pop(stack, top);
	move(arr, stack, &arr_top, top, r - 1, n);
	push(stack, top, n, down_elem);
	free(arr);
}
void print(char* stack, int top) {
	for (int i = top; i >=0; i--) 
		printf("%c", stack[i]);
	printf("\n");
}
int main() {
	int n, m, top = -1, r;
	char* stack = NULL, select[6], c;
	scanf("%d", &n);
	stack = (int*)malloc(n * sizeof(int));
	scanf("%d", &m);
	getchar();
	for (int i = 0; i < m; i++) {
		scanf("%s", select);
		//printf("%d %d %s\n", n, m, select); //
		if (strcmp(select, "PUSH") == 0) {
			getchar();
			scanf("%c", &c);
			push(stack, &top, n, c);
		}
		else if (strcmp(select, "POP")==0) 
			pop(stack, &top);
		else if (strcmp(select, "PEEK") == 0) {
			if (top == -1)
				printf("Stack Empty\n");
			else
				printf("%c\n", stack[top]);
		}
		else if (strcmp(select, "DUP") == 0) 
			duplicate(stack, &top, n);
		else if (strcmp(select, "UpR") == 0) {
			scanf("%d", &r);
			uprotate(stack, r, &top, n);
		}
		else if (strcmp(select, "DownR") == 0) {
			scanf("%d", &r);
			downrotate(stack, r, &top, n);
		}
		else if (strcmp(select, "PRINT") == 0) {
			print(stack, top);
		}
	}
}