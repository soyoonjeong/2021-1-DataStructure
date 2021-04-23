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
	ptr->next = NULL;
	ptr->prev = NULL;
	return ptr;
}
void addnodebefore(NODE**p, int e) {
	printf("여기까지성공\n");
	NODE* newnode = getnode();
	newnode->elem = e;
	if(*p==NULL)
		*p = newnode;
	else{
		printf("여기까지성공3\n");
		newnode->next = (*p)->next;
		newnode->prev = (*p)->prev;
		(*p)->prev->next = newnode;
		(*p)->prev = newnode;
	}
}
void add(NODE **L,int r, char e, int *list) {
	if (r <= 0 || r>(*list)+1) 
		printf("invalid position\n");
	else {
		NODE* p = *L;
		for (int i = 0; i < r - 1; i++) {
			p = p->next;
		}
		addnodebefore(&p, L,e);
		printf("여기까지성공2\n");
		*list += 1;
	}
	
}
void delete(NODE* L, int r, int *list) {
	if (r <= 0 || r>*list) 
		printf("invalid position\n");
	else {
		NODE* p = L;
		for (int i = 0; i < r-1; i++) 
			p = p->next;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		*list -= 1;
	}
}
void get(NODE* L, int r, int list) {
	if (r <= 0 || r > list)
		printf("invalid position\n");
	else {
		NODE* p = L;
		for (int i = 0; i < r-1; i++)
			p = p->next;
		printf("%c\n", p->elem);
	}
}
void print(NODE* L) {
	NODE* p = L;
	while (p == NULL) {
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}
int main() {
	NODE* L = NULL, * pnext, * p;
	int n, i, r, e, list = 0;
	char select;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &select);
		if (select == 'A') {
			scanf("%d %c", &r, &e);
			add(&L, r, e, &list);
		}
		else if (select == 'D') {
			scanf("%d", &r);
			delete(L, r, &list);
		}
		else if (select == 'G') {
			scanf("%d", &r);
			get(L, r, list);
		}
		else if (select == 'P')
			print(L);
	}
	p = L;
	while (p != NULL) {
		pnext = p->next;
		free(p);
		p = pnext;
	}
}