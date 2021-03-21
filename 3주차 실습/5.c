#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void hanoi(int, char, char);
int main() {
	int n;
	scanf("%d", &n);
	hanoi(n, 'A', 'C');
}
void hanoi(int n,char start, char end) {
	int total = 'A' + 'B' + 'C';
	if (n == 1)
		printf("%c %c\n", start, end);
	else {
		hanoi(n - 1, start, total - start-end); //나머지것들 이동
		hanoi(1, start, end); //맨 밑에 있는 것 이동
		hanoi(n - 1, total-start-end, end); //나머지것들 이동
	}

}