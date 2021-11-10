#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char str[100] = "", tmp[100]="";
	int i;
	scanf("%s", str);
	for (i = 0; i < strlen(str); i++) {
		printf("%s", str + i);
		strncpy(tmp, str, i);
		printf("%s", tmp);
		printf("\n");
	}

	return 0;
}
