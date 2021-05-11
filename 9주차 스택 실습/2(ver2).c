#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int push(char* arr, int top, char s) {
	arr[top + 1] = s;
	return top + 1;
}
char pop(char* arr, int* top) {
	if (*top == -1)
		return 'a';
	(*top)--;
	return arr[*top + 1];
}
int openclose_check(char* check, char s) {
	for (int i = 0; i < 3; i++) {
		if (s == check[i])
			return i;
	}
	return 100;
}
int is_balance(char* s, char* arr, int* n) {
	int top = -1, result = 1, idx;
	char open[3] = "({[", close[3] = ")}]", e;
	for (char* ch = s; ch < s + strlen(s); ch++) {
		if (openclose_check(open, *ch) /3==0) { //0,1,2
			top = push(arr, top, *ch);
			(*n)++;
		}
		else{
			idx = openclose_check(close, *ch); //0,1,2
			if (idx / 3 == 0) {
				(*n)++;
				if (top == -1)
					result = 0;
				e = pop(arr, &top);
				if (e!=open[idx])
					result = 0;
			}
		}
	}
	if (top != -1)
		result = 0;
	return result;
}
int main() {
	char s[1001], * arr;
	int n = 0;
	gets(s);
	arr = (char*)malloc(strlen(s) * sizeof(char));
	if (is_balance(s, arr, &n) == 1)
		printf("OK_%d", n);
	else
		printf("Wrong_%d", n);

}