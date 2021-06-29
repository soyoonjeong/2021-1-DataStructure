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
void getTREE(NODE* tree) {
	tree->left = getnode(2, 30);
	tree->left->left = getnode(4, 70);
	tree->left->right = getnode(5, 90);

	tree->right = getnode(3, 50);
	tree->right->right = getnode(6, 120);
	tree->right->right->left = getnode(7, 130);
	tree->right->right->right = getnode(8, 80);
}
void findnode(int id, NODE* node, NODE** result) {
	//printf("%d %d\n", node->id, node->data); //
	if (node->id == id) {
		//printf("%d %d\n", node->id, id); //
		*result = node;
	}
	else {
		if (node->left != NULL && *result == NULL)
			findnode(id, node->left, result);
		if (node->right != NULL && *result == NULL)
			findnode(id, node->right, result);
	}
}
void count_sum(NODE* n, int *sum) {
	*sum += n->data;
	if (n->left != NULL)
		count_sum(n->left, sum);
	if (n->right != NULL)
		count_sum(n->right, sum);
}
int main() {
	NODE* tree = getnode(1, 20), * node = NULL, * result = NULL;
	getTREE(tree);
	int id, sum = 0;
	scanf("%d", &id);
	if (id < 1 || id>8) {
		printf("%d", -1);
		return 0;
	}
	findnode(id, tree, &result);
	count_sum(result, &sum);
	printf("%d",sum);
}