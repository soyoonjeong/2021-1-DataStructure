#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void printnum(int);
int main() {
	int n;
	scanf("%d", &n);
	printnum(n);
}
void printnum(int n) {
	if (n < 10)
		printf("%d\n", n);
	else {
		printnum(n / 10);
		printf("%d\n", n % 10);
	}
}