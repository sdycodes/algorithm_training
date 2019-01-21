#include <stdio.h>
short a[1000005];
int main(int argc, char *argv[]) {
	a[0] = 1;
	a[1] = 2;
	for(int i=2;i<=1000000;i++){
		a[i] = (a[i-1]+a[i-2])%3;
	}
	int n;
	while(scanf("%d", &n)!=EOF){
		if(a[n])	printf("no\n");
		else	printf("yes\n");
	}
}