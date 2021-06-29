#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	int leftData;
	int rightData;
	struct node* left;
	struct node* right;
	struct node* next;
	struct node* parent;
}NODE;
NODE* getnode() {
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn->next = NULL;
	nn->right = NULL;
	nn->left = NULL;
	nn->parent = NULL;
	return nn;
}
void addNode(int data, int left, int right,NODE **last) {
	NODE* nn = getnode();
	nn->data = data;
	nn->leftData = left;
	nn->rightData = right;
	(*last)->next = nn;
	*last = nn;
}
void link(NODE *H, NODE *node,NODE **root) {
	//int flag = 0;
	for (NODE* p = H->next; p!=node; p=p->next) {
		if (p->parent == NULL) {
			if (node->leftData == p->data && node->left == NULL) {
				node->left = p;
				p->parent = node;
			}
			else if (node->rightData == p->data && node->right == NULL) {
				node->right = p;
				p->parent = node;
			}
		}
		if (node->data == p->leftData) {
			p->left = node;
			node->parent = p;
			//flag = 1;
		}
		else if (node->data == p->rightData) {
			p->right = node;
			node->parent = p;
			//flag = 1;
		}
	}
	if (node->parent==NULL)
		*root = node;
}
void print(NODE* H) {
	for (NODE* p = H->next; p != NULL; p = p->next)
		printf(" %d", p->data);
	printf("\n");
}
void printtree(NODE* root, char* str) {
	NODE* p = root;
	printf(" %d", p->data);
	for (char* c = str; *c != '\0'; c++) {
		if (*c == 'R')
			p = p->right;
		else
			p = p->left;
		if (p == NULL)
			break;
		printf(" %d", p->data);
	}
	printf("\n");
}
int main() {
	int n, me, left, right, s;
	NODE* H = getnode(), * last = H, * root = NULL;
	char str[101];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &me, &left, &right);
		addNode(me, left, right, &last);
		link(H, last,&root);
	}
	print(H);
	scanf("%d", &s);
	getchar();
	for (int i = 0; i < s; i++) {
		scanf("%s", str);
		printtree(root, str);
	}
}