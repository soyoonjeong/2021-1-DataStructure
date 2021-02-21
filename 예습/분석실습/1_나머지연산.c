#include <stdio.h>
#pragma warning(disable:4996)

int modulo(int a, int b);
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));
}
int modulo(int a, int b) {
	int i;
	for (i = 0; ; i++) {
		if a < =b* i
			return a - b * i;
	}
}