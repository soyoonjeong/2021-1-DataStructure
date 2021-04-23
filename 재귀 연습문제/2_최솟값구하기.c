#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//3주차 재귀 실습문제 4번 변형
int arrayMin(int* arr, int n) {
	int min;
	if (n == 1)
		return *arr;
	else {
		min = arrayMin(arr + 1, n - 1);
		return (*arr < min) ? *arr : min;
	}
}
int main() {
	int n, * arr;
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	printf("%d", arrayMin(arr, n));
}