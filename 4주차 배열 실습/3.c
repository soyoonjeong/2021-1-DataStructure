#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int n, ** arr, i, col = 0, row = 0, limit, j, move;
	scanf("%d", &n);
	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(n * sizeof(int));
	limit = n - 1;
	move = 1;
	for (i = 1; i <= n*n; i++) {
		arr[row][col] = i;
		if (col == limit) {
			row++; //다음 행으로 이동
			limit = n-1 - limit; //행 번호가 짝수면 다음 행으로 이동하는 기준 limit이 n-1이고,
			                     //행 번호가 홀수면 다음 행으로 이동하는 기준 limit이 0이다.
			move = -move; //행 번호가 짝수면 오른쪽으로 이동(move==1)
			              //행 번호가 홀수면 왼쪽으로 이동(move==-1)
		}
		else
			col += move; 
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}
	for (i = 0; i < n; i++)
		free(arr[i]);
	free(arr);

}