#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sum(int n);

int main() {
	int x, total=0, i;
	scanf("%d", &x);
	for (i = 1; i <= x; i++)
		total += sum(i);
	printf("%d", total);

	return 0;
}

int sum(int n) {
	int i, total=0;
	for (i = 1; i <= n; i++)
		total += i;
	return total;
}
