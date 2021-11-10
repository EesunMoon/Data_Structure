#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void digit(int n);

int main() {
	int n;
	scanf("%d", &n);
	digit(n);

	return 0;
}

void digit(int n) {
	if (n < 10) printf("%d\n", n);
	else {
		digit(n / 10);
		printf("%d\n", n % 10);
	}
}
