#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int n, * arr1, * arr2, * i, * re, j;
	scanf("%d", &n);
	arr1 = (int*)malloc(sizeof(int) * n);
	arr2 = (int*)malloc(sizeof(int) * n);
	for (i = arr1; i < arr1 + n; i++)
		scanf("%d", i);
	for (i = arr2; i < arr2 + n; i++)
		scanf("%d", i);
	re = (int*)malloc(sizeof(int) * n);
	for (j = 0; j < n; j++) {
		re[j] = arr1[j] + arr2[n - 1 - j];
		printf(" %d", re[j]);
	}
	free(arr1);
	free(arr2);
	free(re);
}