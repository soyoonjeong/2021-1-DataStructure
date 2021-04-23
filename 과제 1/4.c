#include <stdio.h>
#pragma warning(disable:4996)
/* 비재귀적으로 작성한 함수는 반복문안의 실행문을 a/b번 반복하고,
* 재귀적으로 작성한 함수는 자기 자신 호출을 a/b번 반복합니다.
* 같은 횟수이지만, 빼기 연산과 비교 연산만 반복하여 스택 메모리를 사용하지 않는 비재귀적 함수와 달리
* 재귀적 함수는 반복적으로 자기자신을 호출하기 때문에
* 연산뿐만 아니라 스택에 새롭게 매개변수 a,b와 호출 위치를 저장합니다.
* 따라서, 재귀적으로 작성한 modulo 함수가 비재귀적으로 작성한 modulo 함수보다 더 복잡합니다.
*/
int modulo(int a, int b) {
	if (a < b)
		return a;
	else if (b == 0)
		return -1;
	else
		modulo(a - b, b);
}
int main()
{
	int a, b, result;
	scanf("%d %d", &a, &b);
	result = modulo(a, b);
	printf("%d\n", result);
	return 0;
}