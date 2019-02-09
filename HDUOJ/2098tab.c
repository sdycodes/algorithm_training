#include <stdio.h>
#include <math.h>

int judgePrime(int n){
	if(n==1)	return 0;
	if(n==2)	return 1;
	for(int i=2;i<=(int)sqrt((float)n)+1;i++)
		if(n%i==0)	return 0;
	return 1;
}
int main(int argc, char *argv[]) {
	int tab[5005] = {0};
	int isPrime[10005];
	for(int i=1;i<=10004;i++)
		isPrime[i] = judgePrime(i);
	for(int i=1;i<=5002;i++){
		for(int j=2;j<i;j++){
			if(isPrime[j]&&isPrime[2*i-j])
				tab[i]++;
		}
	}
	int n;
	while(scanf("%d", &n)&&n!=0){
		printf("%d\n", tab[n/2]);
	}
}