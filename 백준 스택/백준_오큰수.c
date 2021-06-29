#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//핵심 아이디어 : 스택의 탑이 지금 입력받은 수보다 작다면,
//                스택의 탑의 오큰수는 지금 입력받은 수이다. 
typedef struct node {
	int elem;
	int idx;
	struct node* next;
}NODE;
void push(NODE** stack, int i, int e) {
	NODE* nn = (NODE*)malloc(sizeof(NODE));
	nn->elem = e;
	nn->idx = i;
	nn->next = *stack;
	*stack = nn;
}
int main() {
	int n, e, * nge;
	NODE* stack = NULL; //스택
	scanf("%d", &n);
	nge = (int*)malloc(n * sizeof(int)); //이거는 오큰수를 담을 배열 
	for (int i = 0; i < n; i++) {
		scanf("%d", &e); //수를 입력받으면 
		while (stack != NULL) { //스택을 돌아라
			if (stack->elem < e) { //스택을 돌면서 입력받은 수가 스택의 탑보다 더 크다면
				nge[stack->idx] = e; //스택의 탑의 오큰수를 입력받은 수로 저장
				stack = (stack)->next; //pop
			}
			else //입력받은 수가 스택의 탑의 오큰수가 아니라면
				break;
		}
		push(&stack, i, e); //입력받은 수의 오큰수를 찾아야 하기 때문에 스택에 넣자
	}
	while (stack != NULL) { //스택에 남은 수들은 다 오큰수가 -1
		nge[stack->idx] = -1;
		stack = stack->next;
	}
	for (int i = 0; i < n; i++) //오큰수 출력
		printf("%d ", nge[i]);

}