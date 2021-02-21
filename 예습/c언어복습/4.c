#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	char str[101], top;
	int i, j;
	scanf("%s", str);
	printf("%s\n", str);
	for (i = 0; i < strlen(str) - 1; i++) {
		top = str[0];
		for (j = 1; j < strlen(str); j++)
			str[j - 1] = str[j];
		str[strlen(str) - 1] = top;
		printf("%s\n", str);
	}

}