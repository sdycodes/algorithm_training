#include <stdio.h>
#include <string.h>
void output(int s[][305], int l, int r) {
	if (l == r) {
		printf("A%d", l + 1);
		return;
	}
	printf("(");
	int cut = s[l][r];
	output(s, l, cut-1);
	output(s, cut, r);
	printf(")");
	
}
int dp[305][305];
int s[305][305];
int main(int argc, char *argv[]) {
	int N;
	int val[400];
	while(scanf("%d", &N) != EOF) {
		for (int i = 0; i <= N; i++) {
			scanf("%d", &val[i]);
		}
		memset(dp, -1, sizeof(dp));
		memset(s, -1, sizeof(s));
		for (int i = 0; i < N; i++) {
			dp[i][i] = 0;
		}
		for (int i = N - 1; i >= 0; i--) {
			for (int j = i + 1; j < N; j++) {
				for (int k = i + 1; k <= j; k++) {
					if (dp[i][j] == -1 || dp[i][j] >= dp[i][k-1] + dp[k][j] + val[i]*val[k]*val[j+1]) {
						dp[i][j] = dp[i][k-1] + dp[k][j] + val[i]*val[k]*val[j+1];
						s[i][j] = k;
					}
				}
			}
		}
		output(s, 0, N-1);
		//printf("%d\n", dp[0][N-1]);
		printf("\n");
	}
}