#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//미친놈이 연산자 배웠으면서 까먹었냐고 미쳣냐고,, 정수/정수 == 몫인거 누가 모르냐구... 
//아그리고 (int)(n+0.5)으로 반올림하는거 기억하자~!!

//ver2. 
void prefixAverages1(int [], int, int []);
void prefixAverages2(int [], int, int []);

int main()
{
	int n, * X, i, * p = NULL, * j;
	scanf("%d", &n);
	X = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", X + i);
	p = (int*)malloc(n * sizeof(int)); //p 동적할당
	prefixAverages1(X, n, p); //p를 전달하여 p에 값을 넣어주기
	for (i = 0; i < n; i++)
		printf("%d ", p[i]); //배열 p 출력
	printf("\n");
	prefixAverages2(X, n, p);//p를 전달하여 p에 값을 넣어주기
	for (i = 0; i < n; i++)
		printf("%d ", p[i]); //배열 p 출력
	free(p); //메모리 해제
	free(X);

}
void prefixAverages1(int X[], int n, int p[]) {
	double sum;
	int i, j;
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++)
			sum += X[j];
		p[i] = (int)(sum / (i + 1)+0.5); //반올림..ㅜㅜㅜ
	}
}
void prefixAverages2(int X[], int n, int p[]) {
	double sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		sum += X[i];
		p[i] = (int)((sum / (i + 1))+0.5); //반올림..ㅜㅜㅜ
	}
}