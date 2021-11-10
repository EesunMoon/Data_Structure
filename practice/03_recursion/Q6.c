#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b);

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", gcd(a, b));

	return 0;
}

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		if (a == 0) return b;
		else return a;
	}
	else {
		if (a > b) return gcd(b, a%b);
		else return gcd(a, b%a);
	}
}


