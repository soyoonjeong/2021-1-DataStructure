#include <stdio.h>
#pragma warning(disable:4996)

int totalsum(int n);
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", totalsum(n));
}
int totalsum(int n) {
	if (n == 1)
		return 1;
	else
		return totalsum(n - 1) + n;
}