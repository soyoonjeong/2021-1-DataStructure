#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

int* prefixAverages1(int X[], int n);
int* prefixAverages2(int X[], int n);
int main()
{
	clock_t start1, start2, end1, end2;
	int n, * x, i, * a1, * a2;
	scanf("%d", &n);
	x = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		x[i] = rand() % 10000 + 1;
	start1 = clock();
	a1 = prefixAverages1(x, n);
	end1 = clock();
	start2 = clock();
	a2 = prefixAverages2(x, n);
	end2 = clock();
	printf("%.5fms", ((float)end1 - start1) / 1000);
	printf("\n");
	printf("%.5fms", ((float)end2 - start2) / 1000);
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