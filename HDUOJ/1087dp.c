#include <stdio.h>
#include <string.h>

int max(int a, int b){
	return a>b?a:b;
}
int main(int argc, char *argv[]) {
	int n, res;
	int a[1005];
	int dp[1005];
	while(scanf("%d", &n)&&n!=0){
		res = 0;
		memset(dp, 0, sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d", &a[i]);
		}
		a[0] = 0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++)
				if(a[i]>a[j])
					dp[i] = max(dp[i], dp[j]+a[i]);
		}
		for(int i=0;i<=n;i++)
			res = max(res, dp[i]);
		printf("%d\n", res);
	}
	
}