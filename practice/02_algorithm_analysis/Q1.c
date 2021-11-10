#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int modulo(int a, int b);

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));
	return 0;
}

int modulo(int a, int b) {
	int x, y; //x는 두 숫자의 차이, y는 작은 수

	if (a >= b) {
		x = a - b;
		y = b;

		while (x >= y)
			x = x - y;
	}
	else 
		x = a;

	return x;
}
