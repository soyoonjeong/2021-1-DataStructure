#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node* next;
}NODE;
NODE* initialize() {
	NODE* H = (NODE*)malloc(sizeof(NODE));
	H->next = H; 
	return H;
}
void traverse(NODE* H) {
	NODE* p = H->next; //반복문 탈출 기준이 H라는 것이 원형 헤더연결리스트의 핵심
	while (p != H) { //while 버전
		visit(p);
		p = p->next;
	}
	for (p = H->next; p != H; p = p->next) //for버전
		visit(p);
}
int main() {
	NODE* H = initialize();

}