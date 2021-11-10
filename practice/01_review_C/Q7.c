#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int n, *px, *py, i, *p;
	scanf("%d", &n);
	px = (int*)malloc(n * sizeof(int));
	py = (int*)malloc(n * sizeof(int));
	for (p = px; p < px + n; p++)
		scanf("%d", p);
	for (p = py; p < py + n; p++)
		scanf("%d", p);
	for (i = 0; i < n; i++) {
		printf(" %d", *(px + i) + *(py + n - 1 - i));
	}

	free(px);
	free(py);
	return 0;
}
