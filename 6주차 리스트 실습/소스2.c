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
	return ptr;
}
void addnodeafter(NODE *H, int r, int c, int e, int *N) {
	NODE* newnode = getnode(), * p;
	newnode->coef = c;
	newnode->exp = e;
	p = H;
	for (int i = 0; i < r; i++) {
		p = p->next;
		//printf("%d\n", i);
	}
	newnode->next = p->next;
	p->next = newnode;
	*N += 1;
}
void removenode(NODE* H, NODE* ptr, int *N) {
	NODE* prev; //ptr의 전 노드
	for (prev = H->next; prev->next != ptr; prev = prev->next);
	prev->next = ptr->next;
	free(ptr);
	*N -= 1;
}
void addpoly(NODE* H, int c, int e, int *N) {
	NODE* p = H->next, * pnext;
	/*printf("%d %d %d * ", c, e, *N);
	for (p = H->next; p != NULL; p = p->next)
		printf(" %d %d", p->coef, p->exp);
	printf("\n");
	p = H->next;*/
	while (p != NULL) {
		pnext = p->next;
		if (e > p->exp) {
			addnodeafter(H, 0, c, e,N);
			break;
		}
		else if (e < p->exp && p->next == NULL) {
			addnodeafter(H, *N, c, e, N);
			break;
		}
		else if (e == p->exp) {
			if (p->coef + c != 0) 
				p->coef += c;
			else
				removenode(H, p,N);
			break;
		}
		p = pnext;
	}
}
int main()
{
	NODE* H = NULL, * p, * pnext;
	int n, c, e, i, N = 0;
	scanf("%d", &n);
	H = getnode();
	for (i = 0; i < n; i++) {
		scanf("%d %d", &c, &e);
		addnodeafter(H, i, c, e, &N);
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &c, &e);
		addpoly(H, c, e, &N);
	}
	for (p = H->next; p != NULL; p = p->next)
		printf(" %d %d", p->coef, p->exp);

	p = H;
	while (p != NULL) {
		pnext = p->next;
		free(p);
		p = pnext;
	}
}