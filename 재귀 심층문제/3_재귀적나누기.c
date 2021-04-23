#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int* divide(int a, int b) { //쌍으로 반환->배열 주소 반환
	//int* result = (int*)malloc(2 * sizeof(int)); 이런식으로 메모리 할당해도 되고
	int result[2]; //그냥 이렇게 선언해도 됨
	if (a < b) {
		result[0] = 0;
		result[1] = a;
	}
	else {
		result[0] = 1 + divide(a - b, b)[0]; //몫
		result[1] = divide(a - b, b)[1]; //나머지
	}
	return result;
}
int main()
{
	int a, b, * arr;
	scanf("%d %d", &a, &b);
	arr = divide(a, b);
	printf("%d %d", arr[0], arr[1]);
}