#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	char id;
	int rank;
}NODE;

int isfull(int f, int r, int size) {
	return (r + 1) % size == f;
}
int isempty(int f, int r) {
	return f == r;
}
int enqueue(NODE* queue, NODE input, int* f, int* r, int q) {
	if (isfull(*f, *r, q) == 1)
		return 0;
	*r = (*r + 1) % q;
	queue[*r].id = input.id;
	queue[*r].rank = input.rank;
}
NODE dequeue(NODE* queue, int* f, int* r, int q) {
	if (isempty(*f, *r) == 0) {
		*f = (*f + 1) % q;
		return queue[*f];
	}
}
int push(NODE* stack, NODE input, int* t, int s) {
	if (*t == s - 1)
		return 0;
	*t += 1;
	stack[*t].id = input.id;
	stack[*t].rank = input.rank;
}
NODE pop(NODE* stack, int* t, int s) {
	if (*t != -1) {
		*t -= 1;
		return stack[*t + 1];
	}
}
int main() {
	NODE* queue = NULL, * stack = NULL, input;
	int f = 0, r = 0, t = -1;
	int s, q, n;
	scanf("%d", &s);
	stack = (NODE*)malloc(s * sizeof(NODE));
	scanf("%d", &q);
	queue = (NODE*)malloc(q * sizeof(NODE));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c %d", &input.id, &input.rank);
		enqueue(queue, input, &f, &r, q);
	}
	while(isempty(f,r)==0) { //1
		input = dequeue(queue, &f, &r, q);
		if (input.rank == 0)
			printf(" %c", input.id);
		else {
			input.rank -= 1;
			push(stack, input, &t, s);
		}
	} 

	while (t != -1) { //2
		input = pop(stack, &t, s);
		enqueue(queue, input, &f, &r, q);
	}
	while (isempty(f, r) == 0) { //3 นÝบน
		input = dequeue(queue, &f, &r, q);
		if (input.rank == 0)
			printf(" %c", input.id);
		else {
			input.rank -= 1;
			enqueue(queue, input, &f, &r, q);
		}
	}
}