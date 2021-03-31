#include <stdio.h>
#pragma warning(disable:4996)

int modulo(int, int);

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));
}
int modulo(int a, int b) {
	int i, result = a;
	if (a < b)
		return a;
	for (i = 0; ; i++) {
		result -= b;
		if (result< b)
			return result;
	}
}