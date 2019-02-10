#include <stdio.h>

//乌云 为啥powWA 但是循环却可以
int main(int argc, char *argv[]) {
	long long recs[36];
	for(int i=1;i<=35;i++){
		recs[i] = 1;
		for(int j=1;j<=i;j++)
			recs[i]*=3;
		recs[i] -= 1;
	}
	int N;
	while(scanf("%d", &N)!=EOF){
		printf("%lld\n", recs[N]);
	}
}