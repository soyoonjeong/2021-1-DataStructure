#include <stdio.h>
#pragma warning(disable:4996)

int gcd(int, int);
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", gcd(a, b));
}
int gcd(int a, int b) {
	int big, small;
	if (a == 0 || b == 0)
		return a == 0 ? b : a;
	else {
		big = (a > b) ? a : b;
		small = (a > b) ? b : a;
		gcd(small, big % small);
	}
}