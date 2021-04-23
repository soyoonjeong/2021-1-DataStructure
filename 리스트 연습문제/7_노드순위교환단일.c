#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node* next;
}NODE;
NODE* getnode() {
	NODE* ptr = (NODE*)malloc(sizeof(NODE));
	ptr->next = NULL;
	return ptr;
}
void swap1(NODE *H,NODE* p, NODE* q) {
	NODE* ptr, * pprev= NULL, * qprev=NULL, * pnext;
	for (ptr = H; ptr != NULL; ptr = ptr->next) { //단일연결리스트여서 p와 q의 전 노드에 접근할 수가 없어서 pprev와 qprev에 저장하기로 했다!
		if (ptr->next == p) 
			pprev = ptr;
		if (ptr->next == q)
			qprev = ptr;
		if (pprev != NULL && qprev != NULL) //둘다 채워지면 탈출
			break;
	}
	pprev->next = q; //p와 q를 가리키고 있던 노드들 링크부터 정리
	qprev->next = p;
	pnext = p->next; //p->next가 바뀌면 접근할 방법이 없기에 저장
	p->next = q->next; //p와 q의 링크도 바꿔줌
	q->next = pnext;
}
void print(NODE* H) {
	for (NODE* ptr = H->next; ptr != NULL; ptr = ptr->next)
		printf("%d ", ptr->elem);
}
int main() {
	NODE* H = getnode(), * last = H, * nn, * node1, * node2;
	for (int i = 0; i < 3; i++) {
		nn = getnode();
		nn->elem = i;
		last->next = nn;
		last = nn;
	}
	node1 = H->next;
	node2 = H->next->next->next;
	swap1(H, node1, node2);
	print(H);
}