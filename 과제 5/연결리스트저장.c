#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int id;
	struct node* left;
	struct node* right;
	struct node* next;
	struct node* prev;
	int leftid;
	int rightid;
}NODE;
NODE* getnode(int data) {
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn->id = data;
	nn->left = nn->right = nn->next = nn->prev = NULL;
	return nn;
}
NODE * addnode(NODE **last, int me, int left, int right) {
	NODE* nn = getnode(me);
	nn->leftid = left;
	nn->rightid = right;
	nn->prev = *last;
	if(*last!=NULL)
		(*last)->next = nn;
	*last = nn;
	return nn;
}
NODE * findroot(NODE* list) {
	int flag;
	for (NODE* p = list; p != NULL; p = p->next) {
		flag = 0;
		for (NODE* q = list; q != NULL; q = q->next) {
			if (p->id == q->leftid || p->id == q->rightid) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			return p;
	}
}
void link(NODE* root, NODE* list) {
	for (NODE* p = list; p != NULL; p=p->next) {
		if (root->leftid == p->id) {
			root->left = p;
			link(root->left, list);
		}
		if (root->rightid == p->id) {
			root->right = p;
			link(root->right, list);
		}
	}
}
void print(NODE* root, char *c) {
	printf(" %d", root->id);
	if (*c == 'R' && root->right != NULL)
		print(root->right, c + 1);
	if (*c == 'L' && root->left != NULL)
		print(root->left, c + 1);
}
void putnode(NODE* root) {
	if (root->left != NULL)
		putnode(root->left);
	if (root->right != NULL)
		putnode(root->right);
	free(root);
}
int main() {
	int n, me, left, right, s;
	NODE* last = NULL, * list = NULL, * root = NULL;
	char order[101];
	scanf("%d", &n);
	scanf("%d %d %d", &me, &left, &right);
	list = addnode(&last, me, left, right);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d %d", &me, &left, &right);
		addnode(&last, me, left, right);
	}
	root = findroot(list);
	//printf("%d %d %d\n", root->id, root->leftid, root->rightid);
	link(root,list);

	scanf("%d", &s);
	getchar();
	for (int i = 0; i < s; i++) {
		scanf("%s", order);
		print(root, order);
		printf("\n");
	}
	putnode(root);
}