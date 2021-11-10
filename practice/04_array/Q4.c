#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int **x, m, n, num=1;
	int i=0, j=0, mx, nx, cnt=0, flag=0;

	scanf("%d %d", &m, &n);
	mx = m-1; nx = n;

	x = (int **)malloc(m * sizeof(int*));
	for (i = 0; i < m; i++)
		x[i] = (int*)malloc(n * sizeof(int)); //동적할당
	i = 0; j = 0;

	while (num <= m*n) {
		if (flag == 0) { //순방향
			while (cnt < nx) {
				x[i][j] = num;
				num++; j++; cnt++;
			}
			cnt = 0; nx--; 
			i++; j--;
			while (cnt < mx) {
				x[i][j] = num;
				num++; i++; cnt++;
			}
			cnt = 0; mx--; 
			i--; j--; flag = 1;
		}

		else if (flag == 1) { //역방향
			while (cnt < nx) {
				x[i][j] = num;
				num++; j--; cnt++;
			}
			cnt = 0; nx--;
			i--; j++;
			while (cnt < mx) {
				x[i][j] = num;
				num++; i--; cnt++;
			}
			cnt = 0; mx--;
			i++; j++; flag = 0;
		}
	}
//막히면 도는 구조
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
