#include <stdio.h>
#pragma warning(disable:4996)

int sum(int n);

int main()
{
	int x, result = 0;
	scanf("%d", &x);
	for (int i = 1; i <= x; i++)
		result += sum(i);
	printf("%d", result);

}
int sum(int n) {
	if (n == 1)
		return 1;
	return sum(n - 1) + n; //È¸±Í
}