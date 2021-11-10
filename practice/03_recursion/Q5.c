#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rHanoi(int n, char from, char aux, char to);

int main() {
	int n;
	char from = 'A', aux = 'B', to = 'C';
	scanf("%d", &n);
	rHanoi(n, from, aux, to);

	return 0;
}

void rHanoi(int n, char from, char aux, char to) {
	if (n == 1) {
		printf("%c %c\n", from, to);
		return 0;
	}
	rHanoi(n - 1, from, to, aux);
	printf("%c %c\n", from, to);
	rHanoi(n - 1, aux, from, to);
	return 0;
}

