#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int reverse(int* arr, int start, int end) {
	int tmp;
	/* Àç±ÍÀûÀ¸·Î ÀÛ¼º
	if (start >= end)
		return 0;
	else {
		tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		reverse(arr, start + 1, end - 1);
	}*/
	//ºñÀç±ÍÀû
	while (start<end) {
		tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start += 1;
		end -= 1;
	}
}
int main() {
	int n, * x, i, * rev, m;
	scanf("%d", &n);
	x = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", x + i);

	scanf("%d", &m);
	rev = (int*)malloc(m * 2* sizeof(int));
	for (i = 0; i < m*2; i++)
		scanf("%d", rev + i);
	for (i = 0; i < m*2; i += 2) 
		reverse(x, rev[i], rev[i + 1]);
	for (i = 0; i < n; i++)
		printf(" %d", x[i]);
	free(x);
	free(rev);

}