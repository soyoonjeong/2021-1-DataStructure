#include <stdio.h>
#pragma warning(disable:4996)

struct time {
	int h, m, s, total;
};
int main()
{
	struct time t1, t2, gap;
	scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
	scanf("%d %d %d", &t2.h, &t2.m, &t2.s);
	t1.total = t1.h * 3600 + t1.m * 60 + t1.s;
	t2.total = t2.h * 3600 + t2.m * 60 + t2.s;
	gap.total = t2.total - t1.total;
	gap.s = gap.total % 60;
	gap.m = gap.total / 60 % 60;
	gap.h = gap.total / 3600;
	printf("%d %d %d", gap.h, gap.m, gap.s);
}