#include <stdio.h>
#pragma warning(disable:4996)

void printnumreverse(int n);
int main()
{
	int n;
	scanf("%d", &n);
	printnumreverse(n);
}
void printnumreverse(int n) {
	if (n < 10)
		printf("%d\n", n);
	else {
		printf("%d\n", n % 10);
		printnumreverse(n / 10);
	}
}