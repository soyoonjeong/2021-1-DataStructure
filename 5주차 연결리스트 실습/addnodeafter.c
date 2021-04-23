#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	char elem;
	struct node* next;
	struct node* prev;
}NODE;
NODE* getnode() {
	NODE* ptr = (NODE*)malloc(sizeof(NODE));
	ptr->prev = NULL;
	ptr->next = NULL;
	return ptr;
}
void init(NODE** H, NODE** T) {
	*H = getnode();
	*T = getnode();
	(*H)->next = T;
	(*T)->prev = H;
}
void addnodeafter(NODE* p, char e) {
	NODE* newnode = getnode();
	newnode->elem = e;
	newnode->prev = p;
	newnode->next = p->next;
	p->next->prev = newnode;
	p->next = newnode;
}
void add(NODE* H, int r, char e, int* list) {
	NODE* newnode, * p = H;
	if (r > *list + 1 || r <= 0)
		printf("invalid position\n");
	else {
		for (int i = 0; i < r-1; i++)
			p = p->next;
		addnodeafter(p, e);
		*list += 1;
	}
}
void delete(NODE* H, int r, int* list) {
	if (r > *list || r <= 0)
		printf("invalid position\n");
	else {
		NODE* p = H;
		for (int i = 0; i < r; i++)
			p = p->next;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		*list -= 1;
	}
}
char get(NODE* H, int r, int list) {
	if (r > list || r <= 0) {
		printf("invalid position\n");
		return '0';
	}
	else {
		NODE* p = H;
		for (int i = 0; i < r; i++)
			p = p->next;
		return p->elem;
	}
}
void print(NODE* H, NODE* T) {
	for (NODE* p = H->next; p != T; p = p->next)
		printf("%c", p->elem);
	printf("\n");
}
int main() {
	NODE* H = getnode(), * T = getnode();
	int n, i, list = 0, r;
	char menu, e, re;
	H->next = T;
	T->prev = H;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &menu);
		if (menu == 'A') {
			scanf("%d %c", &r, &e);
			add(H, r, e, &list);
		}
		else if (menu == 'D') {
			scanf("%d", &r);
			delete(H, r, &list);
		}
		else if (menu == 'G') {
			scanf("%d", &r);
			re = get(H, r, list);
			if (re != '0')
				printf("%c\n", re);
		}
		else if (menu == 'P')
			print(H, T);
	}
}