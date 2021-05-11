#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int check(char p, char* oper, int* rank) {
	int i;
	for (i = 0; i < 10; i++) {
		if (p == oper[i])
			break;
	}
	return rank[i];
}
void push(char* stack, int* top, char oper) {
	stack[++(*top)] = oper;
}
char pop(char* stack, int* top) {
	(*top)--;
	return stack[*top + 1];
}
void convert(char* str, char* oper, int* rank) {
	//printf("%s\n", str);
	char stack[101];
	int top = -1, flag = 0;
	for (char* p = str; p < str + strlen(str); p++) {
		if (*p >= 'A' && *p <= 'Z')
			printf("%c", *p);
		else if (*p == '(')
			push(stack, &top, *p);
		else if (*p == ')') {
			while (stack[top] != '(')
				printf("%c", pop(stack, &top));
			top--;
		}
		else {
			if (p != str && ( (*(p - 1) >= 'A' && *(p - 1) <= 'Z') || *(p - 1) == ')')) { //앞에 피연산자가 존재할 때

				while ((top != -1) && (check(*p, oper, rank) <= check(stack[top], oper, rank)))
					printf("%c", pop(stack, &top));
			}
		
			//앞에 피연산자 존재하지 않으면 무조건 푸시
			push(stack, &top, *p);
			if (*p == '&' || *p == '|')
				push(stack, &top, *(++p));

		}
	}
	//printf("\n%d\n", top);
	while (top != -1)
		printf("%c", pop(stack, &top));

	printf("\n");

}
int main() {
	char str[101], oper[11] = "*/+-><&|()";
	int rank[10] = {5,5,4,4,3,3,2,1,0,0 }, N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		convert(str, oper, rank);
	}

}