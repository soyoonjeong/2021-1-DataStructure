#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

/* 아래의 소스코드는 ASS,IND, EXP 등의 원시작업이 실행되었고,
   연속되어 있으므로 이들 중 입력문자열의 길이 n에 대하여 최대차수를 가진 항을 선택하여 Big-Oh를 구하겠다.
   소스코드 중 최대 실행시간을 차지하는 것은 문자열을 도는 반복문이다.
   최악의 경우, for문 안의 1번째 if문을 지나치지 못하고 search 함수를 호출하여
   search안의 반복문을 돌고 중첩반복문을 실행하게 된다.
   따라서, 상수계수와 낮은 차수들의 항을 탈락하면 이 소스코드의 Big-Oh = O(n*n)이다.
*/
int search(char*, int start, int end, char);
int main()
{
	char str[101], end;
	int i, j;
	gets_s(str, 101);
	end = strlen(str) - 1;
	for (i = 0; str[i]; i++) {
		if (str[i] == ' ')
			continue;
		if (search(str, 0, i - 1, str[i]) == 0) {
			if (search(str, i + 1, end, str[i]) == 1)
				printf("%c ", str[i]);
		}
		else
			continue;
	}

}
int search(char*str, int start, int end,char ch) {
	int i;
	for (i = start; i <= end; i++) {
		if (str[i] == ch)
			return 1;
	}
	return 0;
}