#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void change(int *before, int* after) {
	int tmp;
	tmp = *after;
	*after = *before; //이동
	*before = tmp; //이동할 수 저장
	
}
int main()
{
	int n, * x, i, len, * arr, * p, before, tmp;
	scanf("%d", &n);
	x = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) 
		scanf("%d", x + i);

	scanf("%d", &len);
	arr = (int*)malloc(len * sizeof(int));  
	for (i = 0; i < len; i++)
		scanf("%d", arr + i);

	before = x[arr[0]]; //before에 이동할 수 저장
	for (p = arr + 1; p < arr + len; p++) 
		change(&before, x + *p);
	for (i = 0; i < n; i++)
		printf(" %d", x[i]);

	free(x);
	free(arr);
}
