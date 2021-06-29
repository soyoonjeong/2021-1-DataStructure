#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//ver1 : 배열 A 전달X, 포인터 반환

int * prefixAverages1(int*, int);
int * prefixAverages2(int *, int);

int main()
{
	int n, * X, i, * p = NULL, * j;
	scanf("%d", &n);
	X = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", X + i);
	p= prefixAverages1(X, n); 
	for (i = 0; i < n; i++)
		printf("%d ", p[i]);
	printf("\n");
	free(p); //메모리 해제

	p = prefixAverages2(X, n);
	for (i = 0; i < n; i++)
		printf("%d ", p[i]);
	free(p); //메모리 해제

	free(X);

}
int * prefixAverages1(int *X, int n) {
	double sum;
	int i, j, * p = NULL;
	p = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) 
			sum += X[j];
		p[i] = (int)(sum / (i + 1)+0.5);
	}
	return p;
}
int* prefixAverages2(int* X, int n) {
	double sum = 0;
	int i, * p = NULL;
	p = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		sum += X[i];
		p[i] = (int)(sum / (i + 1) + 0.5);
	}
	return p;
}