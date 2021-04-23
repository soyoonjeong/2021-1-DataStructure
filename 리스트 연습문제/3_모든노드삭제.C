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
	return ptr;
}
void removeAll(NODE* H, NODE* T) {
	NODE* pnext, * p = H->next;
	while( p != T) {
		pnext = p->next;//우와 우와 깜빡했다 삭제했는데 다음노드로 어떻게 넘어가 멍청쓰야
		remove(p);
		p = pnext;
	}
}
void remove(NODE* p) { //이중연결리스트 노드 삭제
	p->prev->next = p->next; //앞 뒤 노드 조절
	p->next->prev = p->prev;
	free(p); //메모리 해제
}