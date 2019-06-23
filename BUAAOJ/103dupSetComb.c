#include <stdio.h>
#define N 1010
int main(int argc, char * argv[]) {
	int a[N];
	int dp[N][N];
	int n,m,M;
	while(scanf("%d%d%d",&n,&m,&M) != EOF) {
		for(int i = 0; i < n; i++) {
			scanf("%d",&a[i]);
		}
		for(int i = 0; i <= n; i++) {
			dp[i][0] = 1;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
				if(j -1 - a[i-1] >= 0) {
					dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1-a[i-1]] +M)%M;
				} else {
					dp[i][j] = (dp[i-1][j] + dp[i][j-1])%M;
				}
            }
		}
        printf("%d\n",dp[n][m]);
	}
}