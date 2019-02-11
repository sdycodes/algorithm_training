#include <stdio.h>
#include <math.h>
int isPrime(int n){
	if(n==1)	return 0;
	if(n==2)	return 1;
	for(int i=2;i<=(int)sqrt((float)n)+1;i++)
		if(n%i==0)	return 0;
	return 1;
}
int main(int argc, char *argv[]) {
	int T;
	while(scanf("%d", &T)!=EOF){
		int cnt = 0;
		while(T--){
			int n;
			scanf("%d", &n);
			if(isPrime(n))	cnt++;
		}
		printf("%d\n", cnt);
	}
}