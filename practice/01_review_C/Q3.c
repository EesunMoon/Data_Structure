#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *px, int *py);

int main() {
	int n, x[50], a, b, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	scanf("%d %d", &a, &b);
	swap(&x[a], &x[b]);
	for (i = 0; i < n; i++)
		printf(" %d", x[i]);
	return 0;
}

void swap(int *px, int *py) {
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}
