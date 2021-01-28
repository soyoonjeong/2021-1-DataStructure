#include <stdio.h>
#pragma warning(disable:4996)
//1 3 5 7 9 2 4 6 8 10
void ABC(int arr[], int k);
int main()
{
	int n[10], i;
	for (i = 0; i < 10; i++)
		scanf("%d", n + i);
	for (i = 0; i < 9; i++)
		ABC(n, i); //함수에 배열전달
	for (i = 0; i < 10; i++)
		printf(" %d", n[i]);
}
void ABC(int arr[], int k) {
	int i, max = k, tmp;
	for (i = k + 1; i <= 9; i++) {
		if (arr[i] >= arr[max])
			max = i;
	}
	tmp = arr[k];
	arr[k] = arr[max];
	arr[max] = tmp;

}