#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* prefixAverages1(int *x, int n);
int* prefixAverages2(int *x, int n);

int main() {
	int n, *x=NULL, *a=NULL;
	scanf("%d", &n);
	x = (int *)malloc(sizeof(int)*n); //동적할당
	if (x == NULL) return -1; //확인
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);

	a = prefixAverages1(x, n); 
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	a = prefixAverages2(x, n);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	free(x); free(a);//해제
	return 0;
}

int* prefixAverages1(int *x, int n) { //slow version
	int i, j, *a= NULL;
	double sum = 0.0;
	a = (int *)malloc(n * sizeof(int)); //동적할당
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j <= i; j++)
			sum += x[j];
		a[i] = sum / (i + 1) + 0.5;
	}
	return a;
}

int* prefixAverages2(int *x, int n) { //fast version
	int i=0, *a = NULL;
	double sum = 0.0;
	a = (int *)malloc(n * sizeof(int)); //동적할당

	for (i = 0; i < n; i++) {
		sum += x[i];
		a[i] = sum / (i + 1) + 0.5;
	}
	return a;
}
