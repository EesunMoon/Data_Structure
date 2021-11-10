#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ABC(int x[], int k);

int main() {
	int x[10], i;
	for (i = 0; i < 10; i++)
		scanf("%d", &x[i]);
	for (i = 0; i < 9; i++) {
		ABC(x, i);
	}
	for (i = 0; i < 10; i++)
		printf(" %d", x[i]);
	return 0;
}

void ABC(int x[], int k) {
	int i, tmp, max=x[k], maxnum=k;
	for (i = k+1; i < 10; i++) {
		if (max < x[i]) {
			max = x[i];
			maxnum = i;
		}
	}
	tmp = x[k];
	x[k] = x[maxnum];
	x[maxnum] = tmp;
}
