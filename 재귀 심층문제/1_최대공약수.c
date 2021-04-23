#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//3주차 재귀 실습문제 6번
int gcd1(int a, int b) {
	if (a % b == 0)
		return (a > b) ? b : a;
	else 
		return gcd1(b, a % b);
}
int gcd2(int a, int b) {
	if (a == b)
		return a;
	else {
		if (a > b)
			return gcd2(a - b, b);
		else
			return gcd2(a, b - a);
	}
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", gcd2(a, b));
}