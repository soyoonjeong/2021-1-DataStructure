#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/*
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0
*/
int mostOnes(int** A, int n);
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
int mostOnes(int** A, int n) {
	int result = 0, i = 0, j = 0;
	while (i != n - 1 || j != n - 1) {
		while (A[i][j] == 1) {
			if (j == n - 1)
				return result;
			j++;
		}
		i++;
		while (A[i][j] == 0) {
			if (i == n - 1)
				return result;
			i++;
		}
		j++;
		result = i;
	}
	return result;
}