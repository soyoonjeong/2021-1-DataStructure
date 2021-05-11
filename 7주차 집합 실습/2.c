#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node* next;
}NODE;
NODE *getnode() {
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->next = NULL;
	return p;
}
void appendTerm(NODE** last, int e) {
	NODE* nn = getnode();
	nn->elem = e;
	(*last)->next = nn;
	*last = nn;
}
int initialize(NODE* H) {
	int n, e;
	NODE* nn = NULL, * last = H;
	scanf("%d", &n);
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &e);
			appendTerm(&last, e);
		}
	}
}
NODE* UNION(NODE* a, NODE* b) {
	NODE* p = a->next,*q = b->next;
	NODE* result = getnode(), * last = result;
	if (p == NULL)
		return b;
	else if (q == NULL)
		return a;
	else if (p == NULL && q == NULL)
		return result;
	while (p != NULL && q != NULL) {
		if (p->elem < q->elem) {
			appendTerm(&last, p->elem);
			p = p->next;
		}
		else if (p->elem > q->elem) {
			appendTerm(&last, q->elem);
			q= q->next;
		}
		else {
			appendTerm(&last, p->elem);
			p = p->next;
			q = q->next;
		}
	}
	while(p != NULL) {
		appendTerm(&last, p->elem);
		p = p->next;
	}
	while(q != NULL) {
		appendTerm(&last, q->elem);
		q = q->next;
	}
	return result;
}
NODE* INTERSECT(NODE* a, NODE* b) {
	NODE* p = a->next, * q = b->next;
	NODE* result = getnode(), * last = result;
	if (p == NULL || q == NULL)
		return result;
	while (p != NULL && q != NULL) {
		if (p->elem < q->elem)
			p = p->next;
		else if (p->elem > q->elem)
			q = q->next;
		else {
			appendTerm(&last, p->elem);
			p = p->next;
			q = q->next;
		}
	}
	return result;
}
void print(NODE* H) {
	if (H->next == NULL)
		printf(" 0\n");
	else {
		for (NODE* p = H->next; p != NULL; p = p->next)
			printf(" %d", p->elem);
		printf("\n");
	}
}
void putnode(NODE* H) {
	NODE* p = H, * pnext = NULL;
	while (p != NULL) {
		pnext = p->next;
		free(p);
		p = pnext;
	}
}
int main()
{
	NODE* a = getnode(), * b = getnode();
	initialize(a);
	//print(a);
	initialize(b);
	//print(b);
	print(UNION(a, b));
	print(INTERSECT(a, b));
	putnode(a);
	putnode(b);
}