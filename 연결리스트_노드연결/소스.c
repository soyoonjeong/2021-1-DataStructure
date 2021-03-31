#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct NODE {
	char name[21];
	int grade;
	struct NODE* next;
}NODE;

NODE* getnode() {
	NODE* ptr;
	ptr = (NODE*)malloc(sizeof(NODE));
	ptr->next = NULL;
	return ptr;
}
int main() {
	NODE* list = NULL, * last = NULL, * p = NULL, * pnext;
	NODE* newnode, input;
	scanf("%s %d", input.name, &input.grade); //첫 노드 입력받기
	if (strcmp(input.name, "0") != 0) {
		newnode = getnode();
		strcpy(newnode->name, input.name); //입력받은 거 다 복사
		newnode->grade = input.grade;
		list = newnode; //첫 노드 주소를 list에 저장
		last = newnode; //마지막 노드와 첫 노드 같음
	}

	scanf("%s %d", input.name, &input.grade);
	while (strcmp(input.name, "0") != 0) {
		newnode = getnode();
		strcpy(newnode->name, input.name); //입력받은 거 다 복사
		newnode->grade = input.grade;

		last->next = newnode; //맨 마지막에 연결
		last = last->next; //맨 마지막 노드 갱신

		scanf("%s %d", input.name, &input.grade); //다시 입력받기
	}

	p = list; //맨 첫 노드
	while (p) {
		printf("%s %d\n", p->name, p->grade); //확인
		p = p->next;
	}

	p = list; //맨 첫 노드
	while (p) {
		pnext = p->next; //p의 메모리가 해제되기 전 pnext에 다음 노드 주소 저장
		printf("%s\n", p->name);
		free(p); //p 메모리 해제
		p = pnext; //다음 노드를 해제하기 위해 p 갱신
	}



}