#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}NODE;
NODE* getnode(int data) {
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn->data = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}
void gettree(NODE *root, int left, int right) {
	if (left != 0)
		root->left = getnode(left);
	if (right != 0)
		root->right = getnode(right);
}
void findnode(int data, NODE* p, NODE **result) {
	printf("%d ", p->data);
	if (p->left != NULL)
		printf("%d ", p->left->data);
	else
		printf("left null");
	if (p->right != NULL)
		printf("%d ", p->right->data);
	else
		printf("right null");
	printf("\n");
	//printf("들어왔습니다\n");
	if (p->data == data)
		*result = p;
	//if (p->left == NULL)
		//printf("left==null\n");
	//if (p->right == NULL)
		//printf("right==null\n");
	else{
		if (p->left!= NULL && *result==NULL)
			findnode(data, p->left, result);
		if (p->right!= NULL && *result ==NULL)
			findnode(data, p->right, result);
	}
}
int main() {
	int n, s;
	int me, left, right;
	char str[101];
	NODE* tree = NULL, *p=NULL, * result = NULL;
	scanf("%d", &n);
	scanf("%d %d %d", &me, &left, &right);
	tree = getnode(me);
	gettree(tree, left, right); 
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d %d", &me, &left, &right);
		/*
		if (p->left->data == me) {
			//printf("들어왔음\n");
			p = p->left;
		}
		else if (p->right->data == me) 
			p = p->right;
		else {*/
			//printf("enter\n");
		p = NULL;
		findnode(me, tree, &p);
		//printf("%d\n", p->data);
		
		gettree(p, left, right);
		//printf("** %d %d %d\n", p->data, p->left->data, p->right->data);
	}
	scanf("%d", &s);
	getchar();
	for (int i = 0; i < s; i++) {
		scanf("%s", str);
		p = tree;
		printf(" %d", p->data);
		for (char* c = str; *c != '\0'; c++) {
			if (*c == 'R') 
				p = p->right;
			if (*c == 'L') 
				p = p->left;
			printf(" %d", p->data);
		}
		printf("\n");
	}
}