#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#pragma warning(disable:4996)

//배열 A 전달X, 포인터 반환

int* prefixAverages1(int*, int);
int* prefixAverages2(int*, int);

int main()
{
	int n, * X, i, * p = NULL, * j;
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	scanf("%d", &n);
	X = (int*)malloc(n * sizeof(int));
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		X[i] = rand() % 10000 + 1;
	}
	QueryPerformanceFrequency(&ticksPerSec);
	//prefixAverages1 실행시간 측정
	QueryPerformanceCounter(&start);
	p = prefixAverages1(X, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.12f ms\n", 10000 * ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	//prefixAverages2 실행시간 측정
	QueryPerformanceCounter(&start);
	p = prefixAverages2(X, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.12f ms\n", 10000*((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	free(p);
	free(X);

}
int* prefixAverages1(int* X, int n) {
	double sum;
	int i, j, * p = NULL;
	p = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++)
			sum += X[j];
		p[i] = (int)(sum / (i + 1) + 0.5);
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