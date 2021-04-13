#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int coef; //항의 계수(elem)
	int exp; //항의 차수(group)
	struct node* next;
}NODE;

NODE* getnode() {
	NODE* ptr = (NODE*)malloc(sizeof(NODE));
	ptr->next = NULL;
	ptr->coef = 0;
	ptr->exp = 0;
	return ptr;
}
void initialize(NODE** H, int n) { //초기화 
	NODE* i, * newnode, * last;
	*H = getnode();
	last = *H;
	for (int j = 0; j < n; j++) {
		last->next = getnode();
		last = last->next;
	}
}
void input(NODE* H, int n) {
	NODE* p = H->next;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &(p->coef), &(p->exp));
		p = p->next;
	}
}
void appendTerm(NODE** p, int c, int e) { //더블 포인터 방식
	NODE* newnode = getnode();
	newnode->coef = c;
	newnode->exp = e;
	(*p)->next = newnode;
	*p = newnode;
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
			appendTerm(&p, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp) {
			appendTerm(&p, j->coef, j->exp);
			j = j->next;
		}
		else {
			sum = i->coef + j->coef;
			if (sum != 0)
				appendTerm(&p, sum, i->exp);
			i = i->next;
			j = j->next;
		}
	}
	while (i != NULL) {
		appendTerm(&p, i->coef, i->exp);
		i = i->next;
	}
	while (j != NULL) {
		appendTerm(&p, j->coef, j->exp);
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
	NODE* H[2], * p, * result;
	for (i = 0; i < 2; i++) {
		scanf("%d", &n);
		initialize(&H[i], n);
		input(H[i], n);
	}
	result = addpoly(H[0], H[1]);
	for (p = result->next; p != NULL; p = p->next)
		printf(" %d %d", p->coef, p->exp);
	putnode(H[0]);
	putnode(H[1]);
	putnode(result);
}