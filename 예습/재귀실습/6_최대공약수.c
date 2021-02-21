#include <stdio.h>
#pragma warning(disable:4996)
//유클리드 호제법을 이용한 두 정수의 최대공약수 구하기
int gcd(int, int);
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", gcd(a, b));
}
int gcd(int a, int b) {
	int big = (a > b) ? a : b;
	int small = (a > b) ? b : a;
	if (a == 0 || b == 0)
		return big;
	else
		gcd(small, big % small);
}