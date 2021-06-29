#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//첫번째 방법
typedef struct node {
	int id;
	struct node* left;
	struct node* right;
}NODE;

NODE* getnode(int data) {
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn->id = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}
NODE* maketree() {
	int data, left, right;
	NODE* root;
	scanf("%d %d %d", &data, &left, &right);
	root = getnode(data);
	if (left != 0)
		root->left = maketree();
	if (right != 0)
		root->right = maketree();
	return root;
}
void print(char* order, NODE* root) {
	NODE* p = root;
	printf(" %d", p->id);
	for (char* c = order; *c != '\0'; c++) {
		if (*c == 'R')
			p = p->right;
		else if (*c == 'L')
			p = p->left;
		if (p == NULL)
			break;
		printf(" %d", p->id);
	}
	printf("\n");
}
void putnode(NODE* root) {
	if (root->left != NULL)
		putnode(root->left);
	if (root->right != NULL)
		putnode(root->right);
	free(root);
}
int main() {
	int n, s;
	NODE* root = NULL;
	char order[101];
	scanf("%d", &n);
	root = maketree();
	scanf("%d", &s);
	getchar();
	for (int i = 0; i < s; i++) {
		scanf("%s", order);
		print(order, root);
	}
	putnode(root);
}
/*
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//두번째 방법
typedef struct node {
	int id;
	struct node* left;
	struct node* right;
}NODE;
NODE* getnode(int data) {
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn->id = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}
void getchild(NODE *nn, int left, int right) {
	if(left!=0)
		nn->left = getnode(left);
	if (right != 0)
		nn->right = getnode(right);
}
NODE * findnode(NODE* p, int id) {
	NODE* l = NULL;
	if (p == NULL)
		return NULL;
	if (p->id == id)
		return p;
	l = findnode(p->left, id);
	if (l != NULL)
		return l;
	return findnode(p->right, id);
}
void print(char* order, NODE* root) {
	NODE* p = root;
	printf(" %d", p->id);
	for (char* c = order;  *c != '\0'; c++) {
		if (*c == 'R')
			p = p->right;
		else if (*c == 'L')
			p = p->left;
		if (p == NULL) {
			printf("break\n");///

		}
		printf(" %d", p->id);
	}
	printf("\n");
}
void putnode(NODE* root) {
	if (root->left != NULL)
		putnode(root->left);
	if (root->right != NULL)
		putnode(root->right);
	free(root);
}
int main() {
	NODE* root = NULL,* nn = NULL;
	int n, s, me, left, right;
	char order[101];
	scanf("%d", &n);
	scanf("%d %d %d", &me, &left, &right);
	root = getnode(me);
	getchild(root, left, right);
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d %d", &me, &left, &right);
		getchild(findnode(root, me), left, right);

	}
	scanf("%d", &s);
	getchar();
	for (int i = 0; i < s; i++) {
		scanf("%s", order);
		print(order, root);
	}
	putnode(root);
}
*/