#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)
void prefixAverages1(int[], int, int[]);
void prefixAverages2(int[], int, int[]);
int main()
{
	int n, * X, i, * p = NULL, j;
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	scanf("%d", &n);
	X = (int*)malloc(n * sizeof(int));
	p = (int*)malloc(n * sizeof(int)); //p 동적할당

	for (i = 0; i < 5; i++) {
		srand(time(NULL));
		for (j = 0; j < n; j++)
			X[j] = rand() % 10000 + 1;

		printf("%d번째\n", i + 1);
		QueryPerformanceFrequency(&ticksPerSec);

		//prefixAverages1 실행시간 측정
		QueryPerformanceCounter(&start);
		prefixAverages1(X, n, p); //p를 전달하여 p에 값을 넣어주기
		QueryPerformanceCounter(&end);

		diff.QuadPart = end.QuadPart - start.QuadPart;
		printf("prefixAverages1 : %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		//prefixAverages2 실행시간 측정
		QueryPerformanceCounter(&start);
		prefixAverages2(X, n, p);//p를 전달하여 p에 값을 넣어주기
		QueryPerformanceCounter(&end);

		diff.QuadPart = end.QuadPart - start.QuadPart;
		printf("prefixAverages2 : %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	}
	free(p);
	free(X);
}


void prefixAverages1(int X[], int n, int p[]) {
	double sum;
	int i, j;
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++)
			sum += X[j];
		p[i] = (int)(sum / (i + 1) + 0.5);
	}
}


void prefixAverages2(int X[], int n, int p[]) {
	double sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		sum += X[i];
		p[i] = (int)(sum / (i + 1) + 0.5);
	}
}