#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node* next;
	struct node* prev;
}NODE;
NODE* getnode() {
	NODE* ptr = (NODE*)malloc(sizeof(NODE));
	ptr->next = NULL;
	ptr->prev = NULL;
	return ptr;
}
void print(NODE* H) {
	for (NODE* ptr = H->next; ptr != NULL; ptr = ptr->next)
		printf("%d ", ptr->elem);
	printf("\n");
}
void swap2(NODE* p, NODE* q) {
	NODE* pprev, * pnext;
	p->prev->next = q; //p와 q의 앞뒤노드의 링크 바꾸기(p와 q의 링크들은 남아있으니 순서상관없이 막바꿔도됨)
	p->next->prev = q;
	q->prev->next = p;
	q->next->prev = p;
	pprev = p->prev; //p의 prev와 next를 바꾸면 없어지니 미리 저장
	pnext = p->next;
	p->prev = q->prev; //p와 q의 링크 바꾸기
	q->prev = pprev;
	p->next = q->next;
	q->next = pnext;

}
int main() {
	NODE* H = getnode(), * T = getnode(), *last = H, * nn, * node1, * node2;
	H->next = T;
	T->prev = H;
	for (int i = 0; i < 4; i++) {
		nn = getnode();
		nn->elem = i;
		last->next = nn; 
		nn->prev = last;
		last = nn;
	}
	print(H);
	node1 = H->next;
	node2 = H->next->next->next;
	swap2(node1, node2);
	print(H);
}