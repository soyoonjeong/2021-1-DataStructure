#include <stdio.h>
#pragma warning(disable:4996)

struct student {
	char name[10];
	int score;
};
int main()
{
	struct student st[5];
	int i;
	double avg = 0;
	for (i = 0; i < 5; i++) {
		scanf("%s %d", (st + i)->name, &st[i].score);
		avg += st[i].score;
	}
	avg /= 5;
	for (i = 0; i < 5; i++) {
		if (avg >= st[i].score)
			printf("%s\n", st[i].name);
	}
}