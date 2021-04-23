#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//헤더 및 트레일러 이중연결리스트
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
NODE* addFirst(NODE* H, int e) {
	NODE* newnode = getnode();
	newnode->elem = e;
	newnode->prev = H; //먼저 newnode의 링크 정리
	newnode->next = H->next;
	H->next->prev = newnode; //H->next를 먼저 건드리면 H->next->prev를 건드리기 힘들어짐
	H->next = newnode;
	return newnode;
}
NODE* addLast(NODE* T, int e) { //더할 때는 4개의 링크 수정
	NODE* newnode = getnode();
	newnode->elem = e;
	newnode->prev = T->prev; //먼저 newnode의 링크 정리
	newnode->next = T;
	T->prev->next = newnode; //T->prev를 먼저 건드리면 H->next->prev를 건드리기 힘들어짐
	T->prev = newnode;
	return newnode;
}
int removeFirst(NODE* H) {
	NODE* p = H->next; //목표 노드 주소 저장
	int e = p->elem;
	p->prev->next = p->next; //링크 정리
	p->next->prev = p->prev;
	/*
	H->next = p->next;
	p->next->prev = H; 이렇게 p->prev를 H로 대체해도 가능*/
	free(p); //메모리 해제
	return e;
}
int removeLast(NODE* T) {
	NODE* p = T->prev; //목표 노드 주소 저장
	int e = p->elem; 
	p->prev->next = p->next; //링크 정리
	p->next->prev = p->prev;
	/*
	p->prev->next = T;
	T->prev = p->prev; 이렇게 p->next를 T로 대체해도 가능*/
	free(p); //메모리 해제
	return e;
}
