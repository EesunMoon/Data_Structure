#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int *a=NULL, *b=NULL, *p, num, x, i, tmp;

	scanf("%d", &num);
	a = (int *)malloc(sizeof(int)*num);
	for (p = a; p < a + num; p++)
		scanf("%d", p);

	scanf("%d", &x);
	b = (int *)malloc(sizeof(int)*x);
	for (p = b; p < b+x; p++)
		scanf("%d", p);

	tmp = *(a+*(b+x-1));
	for (p = b + x - 1; p > b; p--)
		*(a + *p) = *(a + *(p - 1));
	*(a+*(b+1)) = tmp; //위의 반복문은 n[a[2]]까지만 돌기 때문에

	for (p = a; p < a+num; p++)
		printf(" %d", *p);

	free(a); free(b);
	return 0;
}
