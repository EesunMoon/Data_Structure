#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stu {
	char name[10];
	int score;
}stu;

int main() {
	stu x[5];
	int i, total=0;
	for (i = 0; i < 5; i++) {
		scanf("%s %d", x[i].name, &x[i].score);
		getchar();
		total += x[i].score;
	}
	for (i = 0; i < 5; i++) {
		if ((double)(total) / 5 > x[i].score)
			printf("%s\n", x[i].name);
	}

	return 0;
}
