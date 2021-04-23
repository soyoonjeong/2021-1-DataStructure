#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
//과제 1 3번
/*
int isPalindrome(char* str, int start,int end) {
	if (start >= end)
		return 1;
	else {
		if (str[start] == str[end])
			return isPalindrome(str,start+1,end-1);
		else
			return 0;
	}
}*/
int isPalindrome(char* str, int n) { //이 버전은 왜 안될까 어이가 없다
	if (n <= 1)
		return 1;
	else {
		printf("%c %c\n", *str, *(str + n - 1));
		if ((*str) == *(str + n - 1))
			return isPalindrome(str + 1, n - 1);
		else
			return 0;
	}
}
int main() {
	char str[101];
	scanf("%s", str);
	//printf("%d %d", strlen(str), isPalindrome(str, 0, strlen(str) - 1));
	printf("%d %d", strlen(str), isPalindrome(str, strlen(str)));
}