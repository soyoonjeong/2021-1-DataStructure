#include <stdio.h>
#pragma warning(disable:4996)
#include <stdlib.h>
 
//appendTerm 더블 포인터 방식
typedef struct node {
	int coef;
	int exp;
	struct node* next;
}NODE;

NODE* getnode() {
	NODE* ptr = (NODE*)malloc(sizeof(NODE));
	ptr->next = NULL;
	return ptr;
}
void appendTerm(NODE** last, int c, int e) { // 포인터 반환 
	NODE* newnode = getnode();
	newnode->coef = c;
	newnode->exp = e;
	(*last)->next = newnode;
	*last = newnode;
}
void initialize(NODE *H) {
	int n, c, e, i;
	scanf("%d", &n);
	NODE *last = H;
	for (i = 0; i < n; i++) {
		scanf("%d %d", &c, &e);
		appendTerm(&last, c, e);
	}
}
NODE* addpoly(NODE* x, NODE* y) {
	NODE* result = getnode();
	NODE* i = x->next, * j = y->next, * last = result, * big;
	int sum;
	while (i != NULL && j != NULL) {
		if (i->exp == j->exp) {
			sum = i->coef + j->coef;
			if (sum != 0)
				appendTerm(&last, sum, i -> exp);
			i = i->next;
			j = j->next;
		}
		else if (i->exp > j->exp) {
			appendTerm(&last, i->coef, i->exp);
			i = i->next;
		}
		else {
			appendTerm(&last, j->coef, j->exp);
			j = j->next;
		}
	}
	while (i != NULL) {
		appendTerm(&last, i->coef, i->exp);
		i = i->next;
	}
	while (j != NULL) {
		appendTerm(&last, j->coef, j->exp);
		j = j->next;
	}
	return result;
}
void print(NODE* H) {
	for (NODE* p = H->next; p != NULL; p = p->next)
		printf(" %d %d", p->coef, p->exp);
}
void putnode(NODE* H) {
	NODE* pnext, * p = H;
	while (p != NULL) {
		pnext = p->next;
		free(p);
		p = pnext;
	}
}
int main() {
	int n, i, c, e;
	NODE* a = getnode(), * b = getnode(), * last, * result;
	initialize(a);
	initialize(b);
	result = addpoly(a, b);
	print(result);
	putnode(a);
	putnode(b);
	putnode(result);

}