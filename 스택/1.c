#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int isFull(int f, int r, int size) {
	return (r + 1) % size == f;
}
int isEmpty(int f, int r) {
	return f == r;
}
int push(char* stack_id, int* stack_rank, char id, int rank, int *top, int size) {
	if (*top == size - 1)
		return 0;
	*top += 1;
	stack_id[*top] = id;
	stack_rank[*top] = rank;
}
int push(char* stack, int input, int* top, int size) {
	if (*top == size - 1)
		return 0;
	*top += 1;
	stack[*top] = input;
}
int pop(char* stack_id, int* stack_rank, int* top, int size) {
	if (*top == - 1)
		return 0;
	*top -= 1;
	return *top + 1;
}
int enqueue(char* queue_id, int* queue_rank, char id, int rank, int *f, int *r, int size) {
	if (isFull(*f, *r, size) == 1)
		return 0;
	*r = (*r + 1) % size;
	queue_id[*r] = id;
	queue_rank[*r] = rank;
}
int dequeue(char* queue_id, int* queue_rank, char id, int rank, int* f, int* r, int size) {
	if (isEmpty(*f, *r) == 1)
		return 0;
	int p = *f;
	*f = (*f + 1) % size;
	return p;
}
int main() {
	char* queue_id= NULL, * stack_id = NULL;
	int* queue_rank = NULL, * stack_rank = NULL;
	int s, q, id, rank, idx, n;
	int f = 0, r = 0, t = -1;
	scanf("%d", &q);
	scanf("%d", &s);
	scanf("%d", &n);
	getchar();
	queue_id = (char*)malloc(q * sizeof(char));
	queue_rank = (int*)malloc(q * sizeof(int));
	stack_id = (char*)malloc(s * sizeof(char));
	stack_rank = (int*)malloc(s * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%c %d", &id, &rank);
		getchar();
		enqueue(queue_id, queue_rank, id, rank, &f, &r, q);
		//printf("%c %d\n", queue_id[idx], queue_rank[idx]);
	}
	for (int i = 0; i < n; i++) {
		idx = dequeue(queue_id, queue_rank, id, rank, &f, &r, q);
		if (queue_rank[idx] == 0)
			printf(" %c", queue_id[idx]);
		else {
			queue_rank[idx] -= 1;
			//printf("%c %d\n", queue_id[idx], queue_rank[idx]);//
			push(stack_id, stack_rank, queue_id[idx], queue_rank[idx], &t, s);
		}
	}
	//printf("\n%s\n", stack_id);//
	while(t!=-1) {
		idx = pop(stack_id, stack_rank, &t, s);
		enqueue(queue_id, queue_rank, stack_id[idx], stack_rank[idx], &f, &r, q);
	}
	while (isEmpty(f, r) == 1) {
		for (int i = 0; i < n; i++) {
			idx = dequeue(queue_id, queue_rank, id, rank, &f, &r, q);
			if (queue_rank[idx] == 0)
				printf(" %c", queue_id[idx]);
			else {
				queue_rank[idx] -= 1;
				enqueue(queue_id, queue_rank, queue_id[idx], queue_rank[idx], &f, &r, q);
			}
		}
	}
}