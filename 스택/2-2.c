#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int isFull(int f, int r, int size) {
	return (r + 1) % size == f;
}
int isEmpty(int f, int r) {
	return f == r;
}

int push(char* stack, int input, int* top, int size) {
	if (*top == size - 1)
		return 0;
	*top += 1;
	stack[*top] = input;
}
int pop(char* stack, int* top, int size) {
	if (*top == -1)
		return 0;
	*top -= 1;
	return stack[*top];
}
int enqueue(char* queue, int input, int* f, int* r, int size) {
	if (isFull(*f, *r, size) == 1)
		return 0;
	*r = (*r + 1) % size;
	queue[*r] = input;
}
int dequeue(char* queue, int* f, int* r, int size) {
	if (isEmpty(*f, *r) == 1)
		return 0;
	int p = *f;
	*f = (*f + 1) % size;
	return queue[p];
}
void print(char* stack, int size) {
	for (int i = 0; i < size; i++)
		printf("%c", stack[i]);
	printf("\n");
}
int main() {
	char* queue_id = NULL, * stack_id = NULL;
	int* queue_rank = NULL, * stack_rank = NULL;
	int s, q, id, rank, idx, n;
	int f_id = 0, r_id = 0, t_id = -1;
	int f_r = 0, r_r = 0, t_r = -1;
	scanf("%d", &q);
	scanf("%d", &s);
	scanf("%d", &n);
	queue_id = (char*)malloc(q * sizeof(char));
	queue_rank = (int*)malloc(q * sizeof(int));
	stack_id = (char*)malloc(s * sizeof(char));
	stack_rank = (int*)malloc(s * sizeof(int));
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c %d", &id, &rank);
		//printf("%c\n", id);
		enqueue(queue_id, id, &f_id, &r_id, q);
		enqueue(queue_rank, rank, &f_r, &r_r, q);
	}
	for (int i = 0; i < n; i++)
		printf("%c", queue_id[i]);
	printf("\n");
	for (int i = 0; i < n; i++) {
		id = dequeue(queue_id, &f_id, &r_id, q);
		rank = dequeue(queue_rank, &f_r, &r_r, q);
		if (rank == 0)
			printf(" %c", id);
		else {
			push(stack_id, id, &t_id, s);
			push(stack_rank, rank - 1, &t_r, s);
		}
	}
	printf("\n");
	print(stack_id, t_id);
	while (t_r != -1) {
		id = pop(stack_id, &t_id, s);
		rank = pop(stack_rank, &t_r, s);
		enqueue(queue_id, id , &f_id, &r_id, q);
		enqueue(queue_rank, rank, &f_r, &r_r, q);
	}
	while (isEmpty(f_r, r_r) == 1) {
		for (int i = 0; i < n; i++) {
			id = dequeue(queue_id, &f_id, &r_id, q);
			rank = dequeue(queue_rank, &f_r, &r_r, q);
			if (rank == 0)
				printf(" %c", id);
			else {
				enqueue(queue_id, id, &f_id, &r_id, q);
				enqueue(queue_rank, rank-1, &f_r, &r_r, q);
			}
		}
	}
}