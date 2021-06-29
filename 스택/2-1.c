#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	struct node* left;
	int id;
	int weight;
	struct node* right;
}NODE;
NODE* getnode(int id) {
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn->id = id;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}
void getchild(NODE* root, int left, int right) {
	if (left != 0)
		root->left = getnode(left);
	if (right != 0)
		root->right = getnode(right);
}
NODE * findnode(NODE* root, int id) {
	NODE* l = NULL;
	if (root == NULL)
		return NULL;
	if (root->id == id)
		return root;
	l = findnode(root->left, id);
	if (l != NULL)
		return l;
	return findnode(root->right, id);
}
void print(NODE* root) {
	if (root->left != NULL)
		print(root->left);
	if (root->right != NULL)
		print(root->right);
	printf(" %d", root->weight);
}
int count_h(NODE* root) {
	int l=0, r=0;
	if (root->left == NULL && root->right == NULL)
		return 0;
	if(root->left!=NULL)
		l = count_h(root->left);
	if (root->right != NULL)
		r = count_h(root->right);
	if (l > r)
		return l+1;
	else
		return r+1;

}
void freetree(NODE* root) {
	if (root->left != NULL)
		freetree(root->left);
	if (root->right != NULL)
		freetree(root->right);
	free(root);
}
int main() {
	int n, id, leftid, rightid, weight, * heights = NULL;
	char order;
	NODE* root = NULL, *nn = NULL;
	scanf("%d", &n);
	getchar();
	scanf("%c %d %d %d %d", &order ,&id, &leftid, &rightid, &weight);
	root = getnode(id);
	root->weight = weight;
	getchild(root, leftid, rightid);
	for (int i = 0; i < n-1; i++) {
		getchar();
		scanf("%c", &order);
		if (order == 'A') {
			scanf("%d %d %d %d", &id, &leftid, &rightid, &weight);
			nn = findnode(root, id);
			nn->weight = weight;
			getchild(nn, leftid, rightid);
		}
		else if (order == 'M') {
			scanf("%d %d", &id, &weight);
			nn = findnode(root, id);
			nn->weight = weight;
		}
	}
	print(root);
	printf("\n");
	scanf("%d", &n);
	heights = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &id);
		nn = findnode(root, id);
		if (nn == NULL) {
			heights[i] = -1;
			continue;
		}
		heights[i] = count_h(nn);
	}
	for (int i = 0; i < n; i++)
		printf(" %d", heights[i]);
	freetree(root);
	free(heights);
}