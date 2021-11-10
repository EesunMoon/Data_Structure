#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mostOnes(int A[100][100], int n);

int main() {
	int A[100][100] = { 0 }, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	} //입력
	printf("%d", mostOnes(A, n));

	return 0;
}

int mostOnes(int A[100][100], int n) { //fast version
	int i=0, j=0, row=0;
	while ((i < n) && (j < n)) {
		if (A[i][j] == 0) //0이 나오면 행 내려감
			i += 1;
		else { //1이라면
			row = i; //최대 row는 i행이고
			j += 1; //열 1씩 증가
		} 
	}
	return row;
}
