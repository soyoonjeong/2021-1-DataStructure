#include <stdio.h>
#pragma warning(disable:4996)

int sum(int);
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", sum(n));
}
int sum(int n) {
	if (n == 1)
		return 1;
	else
		return sum(n - 1) + n;
}