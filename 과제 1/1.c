#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/* 아래의 소스코드는 ASS,IND, EXP 등의 원시작업이 실행되었고,
   연속되어 있으므로 이들 중 입력크기 n에 대하여 최대차수를 가진 항을 선택하여 Big-Oh를 구하겠다.
   소스코드 중 최대 실행시간을 차지하는 것은 1부터 n-1까지 배열을 돌면서 max와 min과 비교하는 반복문이다.
   상수계수와 낮은 차수들의 항은 모두 탈락되고 n-1번 반복하기 때문에 이 소스코드의 Big-Oh = O(n) 이다.
*/
int main() {
	int n, * arr, i, max, min;
	scanf("%d", &n); 
	arr = (int*)malloc(n * sizeof(int)); 
	for (i = 0; i < n; i++)  
		scanf("%d", arr + i); 
	max = arr[0];
	min = arr[0];
	for (i = 1; i < n; i++) { 
		if (max < arr[i]) 
			max = arr[i];
		else if (min > arr[i])
			min = arr[i];
	}
	printf("%d %d", max, min);
	free(arr);
	
}