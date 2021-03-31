#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main()
{
	int n, m, ** arr, i, j, row = 0, col = 0, mode = 0, move, limit_ud, limit_lr;
	scanf("%d %d", &n, &m);
	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(m * sizeof(int));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			arr[i][j] = 0;
	}
	move = 1;
	limit_ud = n - 1;
	limit_lr = m - 1;
	for (i = 1; i <= n * m; i++) {
		arr[row][col] = i;
		if (mode%2== 0) { //좌우로 이동
			if (col == limit_lr || arr[row][col+move] != 0 ) {
				mode += 1;
				row += move;
				limit_lr = m- 1 - limit_lr;
				continue;
			}
			col += move;
		}
		else{ //아래위로 이동
			if (row == limit_ud || arr[row+move][col] != 0) {
				mode += 1;
				move = -move; //왼쪽, 위로 이동
				col += move;
				limit_ud = n - 1 - limit_ud;
				continue;
			}
			row += move;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}
	for (i = 0; i < n; i++)
		free(arr[i]); 
	free(arr);
}