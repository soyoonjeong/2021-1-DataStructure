#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int isEmpty(int f, int r) {
	return r == f;
}
int isFull(int f, int r, int N) {
	return (r + 1) % N == f;
}

void print(int* q, int N) {
	for (int i = 0; i < N; i++)
		printf(" %d", q[i]);
	printf("\n");
}

int insert(int* q, int f, int* r,int N,int num) {
	if (isFull(f, *r, N)) {
		printf("overflow");
		print(q, N);
		return -1; //overflow면 반환값 음수
	}
	*r = (*r + 1) % N;
	q[*r] = num;
	return 0;
}

int del(int* q, int* f, int r, int N) {
	if (isEmpty(*f, r)) {
		printf("underflow\n");
		return -1; //underflow면 반환값 음수
	}
	q[*f+1] = 0;
	*f = (*f + 1) % N;
	return 0;
}
int main()
{
	int q, * queue, n, insert_num, result;
	int front = 0, rear = 0;
	char select;
	scanf("%d", &q); //원형 큐의 크기
	scanf("%d", &n); //연산의 개수

	queue = (int*)malloc(q * sizeof(int));
	for (int i = 0; i < q; i++)
		queue[i] = 0;

	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &select);
		if (select == 'I') {
			scanf("%d", &insert_num);
			result = insert(queue, front, &rear, q, insert_num);
			if (result == -1) //overflow면 프로그램 종료
				return 0;
		}
		else if (select == 'D') {
			result = del(queue, &front, rear, q);
			if (result == -1) //underflow면 프로그램 종료
				return 0;
		}
		else if (select == 'P') {
			print(queue, q);
		}
	}
}