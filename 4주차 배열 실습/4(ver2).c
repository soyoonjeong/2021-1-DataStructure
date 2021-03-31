#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//함수 사용
int moveleftright(int** arr, int *num, int *col, int *row, int move, int limit) { //좌우로 이동
	while (1) {
		arr[*row][*col] = (*num)++;
		if (*col == limit || arr[*row][*col + move] != 0) { // 열 번호가 limit에 도달했거나 비어있지 않다면(0이 아니라면)
			*row += move;
			return 0;
		}
		*col += move; //열 증가 또는 감소
	}
}
int moveupdown(int** arr, int* num, int* col, int* row, int move, int limit) { //아래위로 이동
	while (1) {
		arr[*row][*col] = (*num)++;
		if (*row == limit || arr[*row + move][*col] != 0) { //행 번호가 limit에 도달했거나 비어있지 않다면(0이 아니라면)
			*col -= move; 
			return 0;
		}
		*row += move; //행 증가 또는 감소
	}
}
int main()
{
	int n, m, ** arr, i, j, row = 0, col = 0, mode, num;
	scanf("%d %d", &n, &m);
	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(m * sizeof(int));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			arr[i][j] = 0;
	}
	num = 1;
	mode = 0;
	while (num <= n * m) {
		if (mode % 4 == 0) //오른쪽 이동(열 증가)
			moveleftright(arr, &num, &col, &row, 1, m - 1);
		else if (mode % 4 == 1) //아래로 이동(행 증가)
			moveupdown(arr, &num, &col, &row, 1, n - 1);
		else if (mode % 4 == 2) //왼쪽 이동(열 감소)
			moveleftright(arr, &num, &col, &row, -1, 0);
		else //위로 이동(행 감소)
			moveupdown(arr, &num, &col, &row, -1, 0);
		mode++;
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
/* 함수 사용 x
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
				mode += 1; //다음 이동모드로 전환
				row += move; //행 증가 또는 감소
				limit_lr = m- 1 - limit_lr; //limit_lr 전환
				continue;
			}
			col += move; //열 증가 또는 감소
		}
		else{ //아래위로 이동
			if (row == limit_ud || arr[row+move][col] != 0) {
				mode += 1; //다음 이동모드로 전환
				move = -move; //증가->감소 또는 감소->증가
				col += move; //열 증가 또는 감소
				limit_ud = n - 1 - limit_ud; //limit_ud 전환
				continue;
			}
			row += move; //행 증가 또는 감소
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

	//        move  limit_lr limit_ud
	// right  +1      m-1       x
	// left   -1      0         x
	// up     +1      x         0
	// down   -1      x        n-1
}*/