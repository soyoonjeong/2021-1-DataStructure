#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	char elem;
	struct node* next;
	int rank;
}NODE;
NODE* getnode() {
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->next = NULL;
	return p;
}
void push(NODE** t, char elem, int rank) {
	NODE* p = getnode();
	p->elem = elem;
	p->rank = rank;
	p->next = *t;
	*t = p;
}
char pop(NODE** t) {
	char e =(*t)->elem;
	NODE* p = *t;
	(*t) = (*t)->next;
	free(p);
	return e;
}
int findrank(int idx, char *s) {
	if ((idx == 0 || s[idx - 1] < 'A' || s[idx - 1]>'Z') && (s[idx-1]!=')'))
		return 6;
	char str[10] = "|&<>-+/*!";
	int rank[9] = { 1,2,3,3,4,4,5,5,6 };
	for (int i = 0; i < 11; i++) {
		if (s[idx] == str[i]) {
			//printf("%d %c %c\n", i, s[i], str[i]);//
			return rank[i];
		}
	}
}
void change(char* s) {
	NODE* t = NULL;
	int r = 0;
	for (int i=0; s[i]!= '\0'; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			printf("%c", s[i]);
		else if (s[i] == '(') {
			push(&t, '(', 0);
		}
		else if (s[i] == ')') {
			while (t->elem != '(') 
				printf("%c", pop(&t));
			pop(&t);
		}
		else {
			r = findrank(i, s);
			while (t != NULL && (t->rank >= r)) 
				printf("%c", pop(&t));
			push(&t, s[i], r);
			if (s[i] == '&' || s[i] == '|') {
				push(&t, s[i], r);
				i++;
			}
			
		}
	}
	while (t != NULL) {
		printf("%c", pop(&t));
	}
	printf("\n");
}
int main() {
	int n;
	char s[101];
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		change(s);
	}

}
