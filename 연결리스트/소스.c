#include <stdio.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	struct node* link;
}NODE;
int main()
{
	NODE* LIST = NULL, * i;
	NODE node1, node2, node3; 
	node1.data = 1; //data 필드채우기
	node2.data = 5;
	node3.data = 8;

	LIST = &node1; //link로 연결하기
	node1.link = &node2;
	node2.link = &node3;
	node3.link = NULL;

	i = LIST;
	while (i) { //포인터 점프하며 출력
		printf("%d ", i->data);
		i = i->link;
	}
}