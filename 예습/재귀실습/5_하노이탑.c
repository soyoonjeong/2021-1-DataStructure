#include <stdio.h>
#pragma warning(disable:4996)
//하노이탑
void hanoi(int n, int start, int end);
int main() {
	int n;
	scanf("%d", &n);
	hanoi(n, 1, 3);
}
void hanoi(int n, int start, int end) {
	if (n == 1)
		printf("%c %c\n", 'A' - 1 + start, 'A' - 1 + end); //원반이 하나면 다이렉트
	else {
		hanoi(n - 1, start, 6 - start - end); //위 뭉텅이를 시작점과 끝나는점이 아닌 B(6-start-end)에 가져다놈
		hanoi(1, start, end); //맨 아래 원반을 끝나는 점에 가져다놈
		hanoi(n - 1, 6 - start - end, end); //위 뭉텅이들을 끝나는 점에 가져다놈
	}
}