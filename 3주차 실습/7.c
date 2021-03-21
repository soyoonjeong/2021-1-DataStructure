#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int count(char*,int, char);
int main()
{
	char str[101], ch;
	scanf("%s", str);
	getchar();
	scanf("%c", &ch);
	printf("%d", count(str, 0, ch));

}
int count(char*str,int start, char ch) {
	if (start==strlen(str)-1) 
		return str[start] == ch;
	else 
		return count(str, start+1, ch) + (str[start] == ch);
	
}