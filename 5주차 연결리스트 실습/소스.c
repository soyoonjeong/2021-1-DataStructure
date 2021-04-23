#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	char elem;
	struct node* prev;
	struct node* next;
}NODE;

NODE* getnode() {
	NODE* str = (NODE*)malloc(sizeof(NODE));
	str->prev = NULL;
	str->next = NULL;
	return str;
}
NODE* get(NODE* H, int order_rank,int *list) {
	if (order_rank <= 0 || order_rank > *list) {
		printf("invalid position\n");
		return NULL;
	}
	NODE* p = H;
	for (int i = 0; i < order_rank; i++) 
		p = p->next;
	return p;
}
NODE* add(NODE* H, int order_rank, char order_elem, int* list) {
	if (order_rank <= 0 || order_rank > *list+1) {
		printf("invalid position\n");
		return NULL;
	}
	NODE* newnode = getnode(), * p = H;
	newnode->elem = order_elem;
	for (int i = 0; i < order_rank; i++) 
		p = p->next;
	newnode->prev = p->prev;
	newnode->next = p;
	p->prev->next = newnode;
	p->prev = newnode;
	*list += 1;

}
void delete(NODE* H, int order_rank, int *list) {
	NODE* p = NULL;
	p = get(H, order_rank, list);
	if (p != NULL) {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		*list -= 1;
	}
}
void print(NODE* H, NODE* T) {
	NODE* p;
	for (p = H->next; p != T; p = p->next)
		printf("%c", p->elem);
	printf("\n");
}
int main()
{
	int n, i, order_rank, list = 0;
	char order, order_elem;
	NODE * H = getnode(), * T = getnode(), * p, * tmp;
	H->next = T;
	T->prev = H;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &order);
		if (order == 'A') {
			scanf("%d %c", &order_rank, &order_elem);
			add(H, order_rank, order_elem,&list);
		}
		else if (order == 'D') {
			scanf("%d", &order_rank);
			delete(H, order_rank, &list);
		}
		else if (order == 'G') {
			scanf("%d", &order_rank);
			p = get(H, order_rank,&list);
			if(p!=NULL)
				printf("%c\n", p->elem);
		}
		else if(order=='P')
			print(H, T);
	}
	p = H;
	while (p) {
		tmp = p->next;
		free(p);
		p = tmp;
	}
}