#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	int dp[35][35];
	memset(dp, 0, sizeof(dp));
	for(int i=1;i<31;i++){
		dp[i][1] = 1;
		dp[i][i] = 1;
	}
	for(int i=2;i<=30;i++)
		for(int j=2;j<i;j++)
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
	int n;
	while(scanf("%d", &n)!=EOF){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++)
				printf("%d ", dp[i][j]);
			printf("1\n");
		}
		printf("\n");
	}
}