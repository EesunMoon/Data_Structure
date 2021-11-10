#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int **x = { NULL }, n, i, j, num = 1;

	scanf("%d", &n);
	x = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		x[i] = (int *)malloc(n * sizeof(int)); //동적할당

	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (j = 0; j < n; j++) {
				x[i][j] = num;
				num++;
			}
		}
		else {
			for (j = n - 1; j >= 0; j--) {
				x[i][j] = num;
				num++;
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf(" %d", x[i][j]);
		printf("\n");
	}

	for (i = 0; i < n; i++)
		free(x[i]);
	free(x); //해제

	return 0;
}
