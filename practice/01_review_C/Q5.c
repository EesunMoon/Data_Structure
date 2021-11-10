#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct clo {
	int x, y, z;
}clo;

int main() {
	clo c1, c2, c3;
	int cc1, cc2, cc3;
	scanf("%d %d %d", &c1.x, &c1.y, &c1.z);
	scanf("%d %d %d", &c2.x, &c2.y, &c2.z);
	cc1 = c1.z + c1.y * 60 + c1.x * 60 * 60;
	cc2 = c2.z + c2.y * 60 + c2.x * 60 * 60;
	cc3 = cc2 - cc1;
	c3.x = cc3 / (60 * 60);
	c3.y = (cc3 - c3.x * 60 * 60) / 60;
	c3.z = (cc3 - c3.x * 60 * 60) % 60;
	printf("%d %d %d", c3.x, c3.y, c3.z);
	return 0;
}
