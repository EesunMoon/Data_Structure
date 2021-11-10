#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stu {
	char name[8];
	int a, b, c;
	double avg;
}stu;

int main() {
	int n, i;
	stu *p;
	scanf("%d", &n);
	getchar();
	p = (stu*)malloc(n * sizeof(stu));
	for (i = 0; i < n; i++) {
		scanf("%s %d %d %d", p[i].name, &p[i].a, &p[i].b, &p[i].c);
		getchar();
		p[i].avg = (double)(p[i].a + p[i].b + p[i].c) / 3;
	}
	for (i = 0; i < n; i++) {
		printf("%s %.1lf ", p[i].name, p[i].avg);
		if (p[i].a >= 90 || p[i].b >= 90 || p[i].c >= 90) printf("GREAT ");
		if (p[i].a < 70 || p[i].b < 70 || p[i].c < 70) printf("BAD");
		printf("\n");
	}

	free(p);
	return 0;
}
