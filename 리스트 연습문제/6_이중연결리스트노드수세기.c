#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//헤더 및 트레일러 이중연결리스트

typedef struct node {
	int elem;
	struct node* next;
	struct node* prev;
}NODE;
int count(NODE* H, NODE* T) { //비재귀
	int i = 0;
	for (NODE* p = H->next; p != T; p = p->next)
		i += 1;
	return i;
}
int count(NODE* H, NODE* T) {
	return rcount(H->next, T);
}
int rcount(NODE* f, NODE* l) {
	if (f == l)
		return 0;
	else
		return 1 + rcount(f->next, l);
}