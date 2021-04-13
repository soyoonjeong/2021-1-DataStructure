#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//배열 크기를 정하기 힘들어서 연결리스트로 구현해봤는데 됐다
//헤더 단일연결리스트로 구현했다.
//굳이 중간에 삽입또는 삭제 할 필요는 없어서 단일로 했따
//함수전달인자 더블 포인터로 하는거 연습해야겠다 헷갈려요
typedef struct node {
	int num;
	struct node* next;
}NODE;
NODE* getnode()
{
	NODE* str = (NODE*)malloc(sizeof(NODE));
	str->next = NULL;
	return str;
}
void print(NODE* H) {
	for (NODE* p = H->next; p != NULL; p = p->next)
		printf("%d ", p->num);
	printf("\n");
}
void appendTerm(NODE** last, int n) {
	NODE* newnode = getnode();
	newnode->num = n;
	(*last)->next = newnode;
	*last = newnode;
}
void change10to2(NODE *H, NODE **last, int n) {
	if (n == 1) //베이스케이스
		appendTerm(last, 1);
	else {
		change10to2(H, last, n / 2); //점점 작아져 베이스케이스를 향함
		appendTerm(last, n % 2);
	}
	//재귀의 조건 : 
	//1. 베이스케이스(재귀없이 해결 가능)
	//2. 베이스케이스를 향하는 방향
}
int main()
{
	int n;
	NODE* H = getnode(), * p, * last = H;
	scanf("%d", &n);
	change10to2(H, &last, n);
	for (p = H->next; p != NULL; p = p->next)
		printf("%d ", p->num);

}