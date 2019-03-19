#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	int *a = (int*)malloc(sizeof(int)*n);
	int *b = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	b[0] = (a[0]+a[1])>>1;
	b[n-1] = (a[n-1]+a[n-2])>>1;
	for(int i=1;i<n-1;i++){
		b[i] = (a[i-1]+a[i]+a[i+1])/3;
	}
	for(int i=0;i<n;i++)
		printf("%d ", b[i]);
	free(a);
	free(b);
	return 0;
}