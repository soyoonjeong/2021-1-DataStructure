#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

struct student {
	char name[8];
	int score[3];
	double avg;
};
int main()
{
	struct student* st, * i;
	int n, * j;
	scanf("%d", &n);
	st = (struct student*)malloc(sizeof(struct student) * n);
	for (i = st; i < st + n; i++) {
		i->avg = 0;
		scanf("%s", i->name);
		for (j = i->score; j < i->score + 3; j++) {
			scanf("%d", j);
			i->avg += *j;
		}
		i->avg /= 3.0;
	}
	for (i = st; i < st + n; i++) {
		printf("%s %.1f ", i->name, i->avg);
		if (i->score[0] >= 90 || i->score[1] >= 90 || i->score[2] >= 90)
			printf("GOOD ");
		if (i->score[0] <= 70 || i->score[1] <= 70 || i->score[2] <= 70)
			printf("BAD");
		printf("\n");
	}
	free(st);
}