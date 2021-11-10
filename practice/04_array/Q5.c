#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int **x, m, n, i, j, k=0, num=1;
	scanf("%d %d", &m, &n);
	x = (int **)malloc(m * sizeof(int*));
	for (i = 0; i < m; i++)
		x[i] = (int*)malloc(n * sizeof(int)); //동적할당

	while (num <= m*n) {
		for (i = 0, j = k; i <= k, j >= 0; i++, j--) {
			if ((i<m&&j<n)&&(i + j == k)) {
				x[i][j] = num;
				num++;
			}
		}
		k++;
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf(" %d", x[i][j]);
		printf("\n");
	} //출력

	for (i = 0; i < m; i++)
		free(x[i]);
	free(x); //해제

	return 0;
}
