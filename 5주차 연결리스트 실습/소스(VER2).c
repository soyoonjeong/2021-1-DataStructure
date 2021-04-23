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
NODE* get(NODE* H, NODE* T, int order_rank) {
	NODE* p = H;
	for (int i = 0; i < order_rank; i++) {
		p = p->next;
		if (order_rank <= 0 || p == T) {
			printf("invalid position\n");
			return NULL;
		}
	}
	return p;
}
NODE* add(NODE* H, NODE* T, int order_rank, char order_elem) {
	NODE* newnode = getnode(), * p = H;
	newnode->elem = order_elem;
	for (int i = 0; i < order_rank; i++) {
		p = p->next;
		if (order_rank <= 0 || p == NULL) {
			printf("invalid position\n");
			return NULL;
		}
	}
	newnode->prev = p->prev;
	newnode->next = p;
	p->prev->next = newnode;
	p->prev = newnode;

}
void delete(NODE* H, NODE* T, int order_rank) {
	NODE* p = NULL;
	p = get(H, T, order_rank);
	if (p != NULL) {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
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
	int n, i, order_rank;
	char order, order_elem;
	NODE* H = getnode(), * T = getnode(), * p, * tmp;
	H->next = T;
	T->prev = H;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &order);
		if (order == 'A') {
			scanf("%d %c", &order_rank, &order_elem);
			add(H, T, order_rank, order_elem);
		}
		else if (order == 'D') {
			scanf("%d", &order_rank);
			delete(H, T, order_rank);
		}
		else if (order == 'G') {
			scanf("%d", &order_rank);
			p = get(H, T, order_rank);
			if (p != NULL)
				printf("%c\n", p->elem);
		}
		else if (order == 'P')
			print(H, T);
	}
	p = H;
	while (p) {
		tmp = p->next;
		free(p);
		p = tmp;
	}
}