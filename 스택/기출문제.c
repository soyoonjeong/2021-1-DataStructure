#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node {
	char elem;
	struct node* left;
	struct node* right;
}NODE;
NODE* getnode(char elem) {
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn->elem = elem;
	nn->left = NULL;
	nn->right = NULL;
}
int findroot(char* elem, char* left, char* right, int n) {
	int flag = 0;
	for (int i = 0; i < n; i++) {
		flag = 0;
		for (int j = 0; j < n; j++) {
			if (elem[i] == left[j])
				flag = 1;
			if (elem[i] == right[j])
				flag = 1;
		}
		if (flag == 0)
			return i;
	}
}
void getchild(NODE* root, char left, char right) {
	if(left!='0')
		root->left = getnode(left);
	if(right!='0')
		root->right = getnode(right);
}
void link(NODE* root, int rootnum, char* elem, char* left, char* right, int n) {
	if (root->left != NULL) {
		for (int i = 0; i < n; i++) {
			if (root->left->elem == elem[i]) {
				getchild(root->left, left[i], right[i]);
				link(root->left, i, elem, left, right, n);
			}
		}
	}
	if (root->right != NULL) {
		for (int i = 0; i < n; i++) {
			if (root->right->elem == elem[i]) {
				getchild(root->right, left[i], right[i]);
				link(root->right, i, elem, left, right, n);
			}
		}
	}
}
void push(char* stack, int* top, char elem) {
	*top += 1;
	stack[*top] = elem;
}
void pushtree(NODE* root, char *stack, int *top) {
	//printf("%c\n", root->elem);
	push(stack, top, root->elem);
	if (root->left != NULL)
		pushtree(root->left, stack, top);
	if (root->right != NULL)
		pushtree(root->right, stack, top);
}
int ispreorder(char *order,char *stack) {
	return strcmp(stack, order);
}
char pop(char* stack, int* top) {
	*top -= 1;
	return stack[*top - 1];
}
void print(char* stack, int* top) {
	while (*top != -1)
		printf("%c", pop(stack, top));
}
int main() {
	int n, rootnum, top = -1;
	scanf("%d", &n);
	getchar();
	char* order = (char*)malloc((n + 1) * sizeof(char));
	char* stack = (char*)malloc(n * sizeof(char));
	char* elem = (char*)malloc(n * sizeof(char));
	char* left = (char*)malloc(n * sizeof(char));
	char* right = (char*)malloc(n * sizeof(char));
	for (int i = 0; i < n; i++) {
		scanf("%c %c %c", elem + i, left + i, right + i);
		getchar();
	}
	scanf("%s", order);
	rootnum = findroot(elem, left, right, n);
	printf("%d\n", rootnum); //
	NODE* root = getnode(elem[rootnum]);
	getchild(root, left[rootnum], right[rootnum]);
	link(root, rootnum, elem, left, right, n);

	pushtree(root, stack, &top);
	if (ispreorder(order, stack) != 0)
		printf("No\n");
	else
		printf("Yes\n");
	print(stack, &top);

}