#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int* prefixAverages1(int X[], int n);
int* prefixAverages2(int X[], int n);
int main()
{
	int n, * x, i, * a1, * a2;
	scanf("%d", &n);
	x = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", x + i);
	a1 = prefixAverages1(x, n);
	a2 = prefixAverages2(x, n);
	for (i = 0; i < n; i++)
		printf("%d ", a1[i]);
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%d ", a2[i]);
}
int* prefixAverages1(int X[], int n) {
	int i, j, sum, * A;
	A = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++)
			sum += X[j];
		A[i] = sum / (i + 1);
	}
	return A;
}
int* prefixAverages2(int X[], int n) {
	int i, j, sum = 0, * A;
	A = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		sum += X[i];
		A[i] = sum / (i + 1);
	}
	return A;
}