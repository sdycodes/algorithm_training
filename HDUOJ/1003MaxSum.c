#include <stdio.h>

int a[100005];
int dp[100005];
int tag[100005];

int main(int argc, char *argv[]) {
	int T, N, max;
	int k, i, recidx;
	scanf("%d", &T);
	for(int k=1;k<=T;k++){
		max = -100000000;
		if(k!=1)	printf("\n");
		scanf("%d", &N);
		for(i=1;i<=N;i++){
			scanf("%d", &a[i]);
		}
		dp[0] = 0;
		tag[0] = 1;
		for(i=1;i<=N;i++){
			if(dp[i-1]+a[i]>=a[i]){
				dp[i] = dp[i-1]+a[i];
				tag[i] = tag[i-1];
			}
			else {
				dp[i] = a[i];
				tag[i] = i;	
			}
			if(max<dp[i]){
				max = dp[i];
				recidx = i;	
			}
		}
		printf("Case %d:\n", k);
		printf("%d %d %d\n", dp[recidx], tag[recidx], recidx);
	}
}