#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int returnmax(int*,int);
int main()
{
	int n, * arr, i;
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", arr + i);
	printf("%d", returnmax(arr, n));

}
int returnmax(int *p,int n) {
	int i;
	if (n == 1)
		return *p;
	else {
		if (returnmax(p, n - 1) < p[n - 1])
			return p[n - 1];
		return returnmax(p,n - 1);
	}
}