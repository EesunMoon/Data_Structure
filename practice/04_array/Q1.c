#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	int inte;
}node;

int main() {
	node *n;
	int num, x, a, b, i, j, k, tmp;
	scanf("%d", &num);
	n = (node *)malloc(num * sizeof(node)); //동적할당
	for (i = 0; i < num; i++)
		scanf("%d", &((n+i)->inte));
	scanf("%d", &x);
	for (i = 0; i < x; i++) { //x번 실행
		scanf("%d %d", &a, &b);
		for (j = a, k = b; j < k; j++, k--) {
			tmp = (n+j)->inte;
			(n+j)->inte = (n+k)->inte;
			(n+k)->inte = tmp;
		} //뒤집기
	}
	for (i = 0; i < num; i++)
		printf(" %d", (n + i)->inte);

	free(n); //해제
	return 0;
}
