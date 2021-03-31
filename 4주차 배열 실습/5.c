#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main() {
	int n, m, ** arr, i, num, row = 0, col = 0, startrow = 0, startcol = 0, j;
	scanf("%d %d", &n, &m);
	arr = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(m * sizeof(int)); 
	num = 1;
	while (num<=n*m) {
		row = startrow; //대각선 시작 행 번호부터 시작
		col = startcol; //대각선 시작 열 번호부터 시작
		while (0 <= row && row < n && 0 <= col && col < m) //범위 안에 있으면
			arr[row++][col--] = num++; //대각선으로 이동하며 값을 채움
		if (startcol == m - 1) //대각선 시작 행, 열 번호 갱신
			startrow++;
		else
			startcol++;
	}
	for (i = 0; i < n; i++) { 
		for (j = 0; j < m; j++)
			printf(" %d", arr[i][j]); //출력
		printf("\n");
		free(arr[i]); //메모리 해제
	}
	free(arr); //메모리 해제
}