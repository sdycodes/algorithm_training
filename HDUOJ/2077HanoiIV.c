#include <stdio.h>

int main(int argc, char *argv[]) {
	int T;
	long long recs[21];
	for(int i=1;i<=20;i++){
		recs[i] = 1;
		for(int j=1;j<=i-1;j++)
			recs[i] *= 3;
		recs[i] += 1;
	}
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		printf("%lld\n", recs[n]);
	}
}