#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int is_recursion(char *, int, int);
int main() {
	char str[101];
	int len;
	scanf("%s", str);
	len = strlen(str);
	printf("%d %d", len, is_recursion(str,0, len-1));
}
int is_recursion(char*str, int start, int end) {
	if (start >= end)
		return 1;
	else {
		if (str[start] == str[end])
			return is_recursion(str, start + 1, end - 1);
		else
			return 0;
	}
}