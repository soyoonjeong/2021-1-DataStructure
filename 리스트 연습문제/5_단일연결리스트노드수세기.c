#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//단일연결리스트

typedef struct node {
	int elem;
	struct node* next;
}NODE;
int count(NODE* L) { //비재귀
	int i = 0;
	for (NODE* p = L; p != NULL; p=p->next)
		i += 1;
	return i;
}
int count(NODE* L) { //재귀
	if (L->next == NULL) //베이스케이스(노드가 하나밖에 없을때)
		return 1;
	else
		return 1 + count(L->next); //노드점프해서 함수 호출->베이스케이스를 향해 가는 중

}
