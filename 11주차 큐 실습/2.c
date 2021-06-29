#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node {
	int elem;
	struct node* prev;
	struct node* next;
}DEQUE;

DEQUE* getnode(int num) {
	DEQUE* n = (DEQUE*)malloc(sizeof(DEQUE));
	n->prev = NULL;
	n->next = NULL;
	n->elem = num;
	return n;
}
void add_front(DEQUE** f, DEQUE **r, int num) {
	DEQUE* n = getnode(num);
	n->next = *f;
	if(*f!=NULL) //데크 원소 개수가 0이 아닐 경우
		(*f)->prev = n;
	*f = n; //추가
	if (*r == NULL) //첫 원소면 rear도 갱신해줌
		*r = n;
}
void add_rear(DEQUE** f, DEQUE** r, int num) {
	DEQUE* n = getnode(num);
	n->prev = *r;
	if (*r != NULL) //데크 원소 개수가 0이 아닐 경우
		(*r)->next = n;
	*r = n; //추가
	if (*f == NULL) //첫 원소면 front도 갱신해줌
		*f = n;
}
int delete_front(DEQUE** f, DEQUE **r) {
	if (*f == NULL) { //empty
		printf("underflow\n");
		return -1;
	}
	DEQUE* dnode = *f; //삭제할 원소 저장
	int e = (*f)->elem;
	if (*r == *f) //만약 원소가 하나만 남았다면 
		*r = NULL;
	*f = (*f)->next; //front 이동
	if(*f!=NULL) //삭제 후 원소가 남았다면 
		(*f)->prev = NULL;
	free(dnode); //메모리 해제
	return e;
}
int delete_rear(DEQUE **f, DEQUE** r) {
	if (*r == NULL) { //empty
		printf("underflow\n");
		return -1;
	}
	DEQUE* dnode = *r; //삭제할 원소 저장
	int e = (*r)->elem;
	if (*r == *f) //만약 원소가 하나만 남았다면
		*f = NULL;
	*r = (*r)->prev; //rear 이동
	if(*r!=NULL) //삭제 후 원소가 남았다면 
		(*r)->next = NULL;
	free(dnode); //메모리 해제
	return e;
}
void print(DEQUE* f) {
	for (DEQUE* p = f; p != NULL; p = p->next)
		printf(" %d", p->elem);
	printf("\n");
}
int main()
{
	int n, add_num, result = 0;
	char select[3];
	DEQUE* front = NULL, * rear = NULL;
	scanf("%d", &n);
	for (int i=0; i < n; i++) {
		getchar();
		scanf("%s", select);
		//printf("%d\n", i);
		if (strcmp(select, "AF") == 0) {
			scanf("%d", &add_num);
			add_front(&front, &rear, add_num);
		}
		else if (strcmp(select, "AR") == 0) {
			scanf("%d", &add_num);
			add_rear(&front, &rear, add_num);
		}
		else if (strcmp(select, "DF") == 0) {
			result = delete_front(&front, &rear);
			if (result == -1)
				return 0;
		}
		else if (strcmp(select, "DR") == 0) {
			result = delete_rear(&front, &rear);
			if (result == -1)
				return 0;
		}
		else if (strcmp(select, "P") == 0) {
			print(front);
		}
	}
	DEQUE* p = front, * del;
	while (p != NULL) {
		del = p->next;
		free(p);
		p = del;
	}
}