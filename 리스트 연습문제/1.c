#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void rElements(int *A,int i, int n) {
	if (i < n) {
		printf("%d", A[i]);
		return rElements(A, i + 1, n); //재귀, 베이스케이스(i>=n)을 향해가고 있음
	}
	//베이스케이스(i>=n)
}