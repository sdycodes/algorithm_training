#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	int P,N;
	int p[400];
	int c[400];
	int dp[20005];
	while(scanf("%d%d", &P, &N) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &p[i], &c[i]);
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; i++) {
			for (int j = c[i]; j <= P; j++) {
				if (dp[j] < dp[j - c[i]] + p[i]) {
					dp[j] = dp[j - c[i]] + p[i];
				}
			}
		}
		printf("%d\n", dp[P]);
	}
	return 0;
}