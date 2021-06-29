#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
	int id;
	struct node* left;
	struct node* right;
}NODE;
NODE* getnode(int id) {
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn->id = id;
	nn->left = nn->right = NULL;
	return nn;
}
void getchild(NODE* nn, int left, int right) {
	if (left != 0)
		nn->left = getnode(left);
	if (right != 0)
		nn->right = getnode(right);
}
void link(NODE* root, int *arr, int n) {
	if (root->left != NULL) {
		for (int i = 0; i < 3 * n; i+=3) {
			if (arr[i] == root->left->id) {
				getchild(root->left, arr[i + 1], arr[i + 2]);
				link(root->left,arr,n);
				break;
			}
		}
	}
	if (root->right != NULL) {
		for (int i = 0; i < 3 * n; i += 3) {
			if (arr[i] == root->right->id) {
				getchild(root->right, arr[i + 1], arr[i + 2]);
				link(root->right, arr, n);
				break;
			}
		}
	}
}
int findroot(int* arr, int n) {
	int flag;
	for (int i = 0; i < 3 * n; i += 3) {
		flag = 0;
		for (int j = 0; j < 3 * n; j++) {
			if (j % 3 == 0)
				continue;
			if (arr[j] == arr[i]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			return i;
	}
}
void print(NODE* root, char *c) {
	printf(" %d", root->id);
	if (*c=='L' && root->left != NULL)
		print(root->left, c+1);
	if (*c=='R' && root->right != NULL)
		print(root->right,c+1);
}
void putnode(NODE* root) {
	if (root->left != NULL)
		putnode(root->left);
	if (root->right != NULL)
		putnode(root->right);
	free(root);
}
int main() {
	int n, me, left, right, * arr = NULL, rootnum, s;
	NODE* root = NULL;
	char order[101];

	scanf("%d", &n);
	arr = (int*)malloc(3 * n * sizeof(int));
	for (int i = 0; i < 3*n; i+=3) 
		scanf("%d %d %d", arr+i, arr+i+1, arr+i+2);

	rootnum = findroot(arr,n);
	root= getnode(arr[rootnum]);
	getchild(root, arr[rootnum + 1], arr[rootnum + 2]);

	link(root, arr, n);

	scanf("%d", &s);
	getchar();
	for (int i = 0; i < s; i++) {
		scanf("%s", order);
		print(root, order);
		printf("\n");
	}
	putnode(root);
}