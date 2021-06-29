#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int * initqueue(int* f, int* r, int q) {
	int *p= (int*)malloc(q * sizeof(int));
	for (int* i = p; i < p + q; i++)
		*i = 0;
	*f = 0;
	*r = 0;
	return p;
}
int isEmpty(int f, int r) {
	return f == r;
}
int isFull(int f, int r, int q) {
	return f == (r + 1) % q;
}
void print(int* queue, int q) {
	for (int i = 0; i < q; i++)
		printf(" %d", queue[i]);
	printf("\n");
}
int enqueue(int* queue, int size, int *f, int* r, int e) {
	if (isFull(*f, *r, size) == 1) {
		printf("overflow");
		print(queue, size);
		return 0;
	}
	*r = (*r + 1) % size;
	queue[*r] = e;
	return 1;
}
int dequeue(int* queue, int size, int* f, int *r) {
	if (isEmpty(*f, *r) == 1) {
		printf("underflow\n");
		return 0;
	}
	queue[*f+1] = 0;
	*f = (*f + 1) % size;
	return 1;
}
int main() {
	int f, r, q, * queue = NULL, n, e, result;
	char select;
	scanf("%d", &q);
	queue = initqueue(&f, &r, q);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &select);
		if (select == 'I') {
			scanf("%d", &e);
			result = enqueue(queue, q, &f, &r, e);
			if (result == 0)
				break;
		}
		else if (select == 'D') {
			result = dequeue(queue, q, &f, &r);
			if (result == 0)
				break;
		}
		else if (select == 'P')
			print(queue, q);
	}

}