#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int mostOnes(int**, int);

int main()
{
	int n, ** arr, i, j;
	scanf("%d", &n);
	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf("%d", &(arr[i][j]));
	}
	printf("%d", mostOnes(arr, n));

}

int mostOnes(int**A, int n) {
	int i = 0, j = 0, maxline=0;
	while(1) {
		while (A[i][j] == 1) { //오른쪽으로 이동
			j++;
			if (j == n)
				return i;
		}
		maxline = i;
		while (A[i][j] == 0) { //아래로 이동
			i++;
			if (i == n)
				return maxline;
		}
		maxline = i;
	}
	//return maxline;
}