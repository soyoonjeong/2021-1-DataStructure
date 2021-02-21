#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int count(char* str, char ch);
int main()
{
	char str[101], ch;
	scanf("%s", str);
	getchar();
	scanf("%c", &ch);
	printf("%d", count(str, ch));
}
int count(char* str, char ch) {
	int i = 0, plus;
	if (i == strlen(str) - 2)
		return (str[i + 1] == ch) ? 1 : 0;
	else {
		plus = (str[i] == ch) ? 1 : 0;
		return count(str + i + 1, ch) + plus;
	}
}