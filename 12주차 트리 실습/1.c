#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}TREE;
TREE* getnode(int data) {
	TREE* nn = (TREE*)malloc(sizeof(TREE));
	nn->data = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}
TREE* getparent(TREE* left, TREE* right, int data) {
	TREE* p = getnode(data);
	p->left = left;
	p->right = right;
	return p;
}
void print(TREE** F, int n) {
	if (n < 1 || n >8)
		printf("%d", -1);
	else {
		printf("%d ", F[n]->data);
		if (F[n]->left != NULL)
			printf("%d ", F[n]->left->data);
		if (F[n]->right != NULL)
			printf("%d ", F[n]->right->data);
	}
}
int main() {
	TREE *F[9];
	F[4] = getnode(70);
	F[5] = getnode(90);
	F[2] = getparent(F[4], F[5], 30);

	F[7] = getnode(130);
	F[8] = getnode(80);
	F[6] = getparent(F[7], F[8], 120);

	F[3] = getparent(NULL, F[6], 50);

	F[1] = getparent(F[2], F[3], 20);

	int n;
	scanf("%d", &n);

	print(F, n);

}