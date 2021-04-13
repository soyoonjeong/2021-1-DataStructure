#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int* prefixAverages1(int* x, int n) {
	int* arr = (int*)malloc(n * sizeof(int)), i, j;
	double sum;
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++)
			sum += x[j];
		arr[i] = (int)(sum / (i + 1) + 0.5);
	}
	return arr;
}
int* prefixAverages2(int* x, int n) {
	int* arr = (int*)malloc(n * sizeof(int)), i;
	double sum = 0;
	for (i = 0; i < n; i++) {
		sum += x[i];
		arr[i] = (int)(sum / (i + 1)+0.5);
	}
	return arr;
}
void print(int* arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	int n, * arr, i, * avg1, * avg2;
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", arr + i);
	avg1 = prefixAverages1(arr, n);
	avg2 = prefixAverages2(arr, n);
	print(avg1, n);
	print(avg2, n);
	free(arr);
	free(avg1);
	free(avg2);
}