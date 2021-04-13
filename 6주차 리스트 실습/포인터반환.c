#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//appendTerm 포인터 반환 방식

typedef struct node {
	int coef; //항의 계수(elem)
	int exp; //항의 차수(group)
	struct node* next;
}NODE;

NODE* getnode() {
	NODE* ptr = (NODE*)malloc(sizeof(NODE));
	ptr->next = NULL;
	return ptr;
}
NODE *appendTerm(NODE* last, int c, int e) { //포인터 반환 방식
	NODE* newnode = getnode();
	newnode->coef = c;
	newnode->exp = e;
	last->next = newnode;
	return newnode;
}
NODE* addpoly(NODE* x, NODE* y) {
	NODE* i, * j, * p, * n;
	int sum = 0;
	NODE* result = getnode();
	i = x->next;
	j = y->next;
	p = result;
	while (i != NULL && j != NULL) {
		if (i->exp > j->exp) {
			p = appendTerm(p, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp) {
			p = appendTerm(p, j->coef, j->exp);
			j = j->next;
		}
		else {
			sum = i->coef + j->coef;
			if (sum != 0)
				p = appendTerm(p, sum, i->exp);
			i = i->next;
			j = j->next;
		}
	}
	while (i != NULL) {
		p = appendTerm(p, i->coef, i->exp);
		i = i->next;
	}
	while (j != NULL) {
		p = appendTerm(p, j->coef, j->exp);
		j = j->next;
	}
	return result;
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
	int n, i, j, c, e;
	NODE* H[2], * p, * result, * last;
	for (i = 0; i < 2; i++) {
		scanf("%d", &n);
		H[i] = getnode();
		last = H[i];
		for (j = 0; j < n; j++) {
			scanf("%d %d", &c, &e);
			last = appendTerm(last, c, e);
		}
	}
	result = addpoly(H[0], H[1]);
	for (p = result->next; p != NULL; p = p->next)
		printf(" %d %d", p->coef, p->exp);
	putnode(H[0]);
	putnode(H[1]);
	putnode(result);
}