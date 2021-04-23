#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int substr(char* s, char* t) {
	int index;
	for (char* i = s; i != NULL; i++) {
		if (*i == *t) {
			
		}
	}
	return -1;
}
int main()
{
	char s[101], t[101];
	gets(s);
	getchar();
	gets(t);
	printf("%d", substr(s, t));
}