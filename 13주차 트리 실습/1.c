#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	int id;
	struct node* left;
	struct node* right;
}NODE;
NODE* getnode(int id, int data) {
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn->id = id;
	nn->data = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}
void findnode(int id, NODE* node, NODE **result) {
	//printf("%d %d\n", node->id, node->data); //
	if (node->id == id) {
		//printf("%d %d\n", node->id, id); //
		*result = node;
	}
	else {
		if (node->left != NULL && *result ==NULL)
			findnode(id, node->left,result);
		if (node->right != NULL && *result==NULL)
			findnode(id, node->right, result);
	}
}
void preorder(NODE* n) {
	printf(" %d", n->data);
	if (n->left != NULL)
		preorder(n->left);
	if (n->right != NULL)
		preorder(n->right);
}
void inorder(NODE* n) {
	if (n->left != NULL)
		inorder(n->left);
	printf(" %d", n->data);
	if (n->right != NULL)
		inorder(n->right);
}
void postorder(NODE* n) {
	if (n->left != NULL )
		postorder(n->left);
	if (n->right != NULL)
		postorder(n->right);
	printf(" %d", n->data);
}
int main() {
	NODE* tree = getnode(1, 20), * node = NULL, * result = NULL;

	tree->left = getnode(2, 30);
	tree->left->left = getnode(4, 70);
	tree->left->right = getnode(5, 90);

	tree->right = getnode(3, 50);
	tree->right->right = getnode(6, 120);
	tree->right->right->left = getnode(7, 130);
	tree->right->right->right = getnode(8, 80);

	int method, id;
	scanf("%d %d", &method, &id);
	if (id < 1 || id>8) {
		printf("%d", -1);
		return 0;
	}
	findnode(id, tree, &result);
	//printf("%d\n", result->data); //
	if (method == 1) 
		preorder(result);
	else if (method == 2)
		inorder(result);
	else if (method == 3)
		postorder(result);
}