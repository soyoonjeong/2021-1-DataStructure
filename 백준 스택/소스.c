#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int input(char* str) {
	int i;
	for (i = 0; ; i++) {
		scanf("%c", &(str[i]));
		if (str[i] == '.') {
			str[i + 1] = NULL;
			return 0;
		}
	}
}
int check(char s, char *str) {
	for (int i = 0; i < 3; i++) {
		if (s == str[i])
			return i;
	}
	return 100;
}
void print(char* stack,int top) {
	for (int i = 0; i <= top; i++)
		printf("%c ", stack[i]);
	printf("\n");
}
int main() {
	char str[101], stack[101];
	char open[3] = "({[", close[3] = ")}]";
	int top = -1, idx, flag = 0;
	input(str);
	//gets(str);
	//printf("%s\n", str);
	while (str[0]!='.') {
		for (int i = 0; str[i] != '.'; i++) {
			//print(stack, top);
			if (check(str[i], open) / 3 == 0)
				stack[++top] =str[i];
			else{
				idx = check(str[i], close);
				if (idx/3 == 0) {
					if (top == -1 ) {
						flag = 1;
						break;
					}
					if (open[idx] != stack[top]) {
						flag = 1;
						break;
					}
					else
						top--;
				}
			}
		}
		if (flag == 0)
			printf("yes\n");
		else
			printf("no\n");
		input(str);
		flag = 0;
	}
}