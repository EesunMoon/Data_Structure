#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int n);

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", add(n));

	return 0;
}

int add(int n) {
	if (n == 1) return 1;
	else return n + add(n - 1);
}
