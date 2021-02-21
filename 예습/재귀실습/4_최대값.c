#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int findmax(int arr[], int n);
int main()
{
	int n, * arr, i;
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", arr + i);
	printf("%d", findmax(arr, n));

}
int findmax(int arr[], int n) {
	if (n == 1)
		return arr[0];
	else
		return (findmax(arr, n - 1) > arr[n - 1]) ? findmax(arr, n - 1) : arr[n - 1];
}