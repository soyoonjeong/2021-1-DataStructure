#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void hanoi(int n, char from, char aux, char to) {
	if (n == 1)
		printf("%c %c\n", from, to);
	else {
		printf("%c %c\n", from, aux);
		hanoi(n - 1, from, aux,to);
		printf("%c %c\n", aux, to);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
}