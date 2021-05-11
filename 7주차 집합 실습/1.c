#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node* next;
}NODE;
NODE* getnode() {
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->next = NULL;
	return p;
}
void add(NODE **last, int e) {
	NODE* nn = getnode();
	nn->elem = e;
	(*last)->next = nn;
	(*last) = nn;
}
int initialize(NODE** f) {
	NODE* last;
	int n, e;
	scanf("%d", &n);
	if (n == 0)
		return 0;
	*f = getnode();
	scanf("%d", &((*f)->elem));
	last = *f;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &e);
		add(&last, e);
	}
}
void print(NODE* a) {
	for (NODE* p = a; p != NULL; p = p->next)
		printf("%d ", p->elem);
	printf("\n");
}
int subset(NODE* a, NODE* b) {
	if(a==NULL) 
		return 0;
	if (b == NULL)
		return a->elem;
	NODE* p = a, * q = b;
	while (1) { //while(p!=NULL && q!=NULL) 이것도 해보기
		if (p->elem < q->elem) 
			return p->elem;
		else if (p->elem > q->elem) {
			if (q->next == NULL) 
				return p->elem;
			q = q->next;
		}
		else {
			if (p->next == NULL)
				return 0;
			if (q->next == NULL)
				return p->elem;
			p = p->next;
			q = q->next;
		}
	}
}
void putnode(NODE* a) {
	NODE* p = a, *pnext = NULL;
	while (p) {
		pnext = p->next;
		free(p);
		p = pnext;
	}	
}
int main()
{
	int n, e;
	NODE* a=NULL, * b=NULL ;
	initialize(&a);
	initialize(&b);
	printf("%d",subset(a, b));
	putnode(a);
	putnode(b);
}