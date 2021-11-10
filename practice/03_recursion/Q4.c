#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxi(int x[], int xx, int nx);

int main() {
	int n, i, x[20];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	printf("%d", maxi(x, x[n-1], n-1));

	return 0;
}

int maxi(int x[], int xx, int nx) {
	//xx는 최대를 나타내는 말
	if (nx==0) {
		if (xx < x[nx]) return x[nx];
		return xx;
	}
	
	if (xx<x[nx])
		xx = x[nx];
	xx=maxi(x, xx, nx - 1);
}
