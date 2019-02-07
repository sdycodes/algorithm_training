#include <stdio.h>
int fibCow(int n){
	if(n<=4)	return n;
	return fibCow(n-3)+fibCow(n-1);
}
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)&&n!=0)
		printf("%d\n", fibCow(n));
	return 0;
}