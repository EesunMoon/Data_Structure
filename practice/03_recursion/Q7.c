#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int s(char x[], char y, int num, int cnt);

int main() {
	char x[100] = { NULL }, y = NULL;
	scanf("%s", x);
	getchar();
	scanf("%c", &y);
	printf("%d", s(x, y, strlen(x)-1, 0));

	return 0;
}

int s(char x[], char y, int num, int cnt) {
	if (num == 0) {
		if (y == x[num]) cnt++;
		return cnt;
	}
	if (y == x[num]) cnt++;
	return s(x, y, num - 1, cnt);
}
