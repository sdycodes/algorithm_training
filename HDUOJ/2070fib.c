#include <stdio.h>

long long fib(int n){
	if(n<=1) return n;
	long long a=0, b=1;
	for(int i=1;i<=n/2;i++){
		a = a+b;
		b = a+b;
	}
	return n%2==0?a:b;
}
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)&&n!=-1){
		long long res = fib(n);
		printf("%lld\n", res);
	}
}