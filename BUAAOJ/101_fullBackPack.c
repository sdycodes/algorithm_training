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
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = P; j >= c[i]; j--) {
				if (dp[j-c[i]]!=-1 && dp[j] < dp[j-c[i]] + p[i]) {
					dp[j] = dp[j-c[i]] + p[i];
				}
			}
		}
		if (dp[P] == -1) {
			printf("jpx\n");
		} else {
			printf("%d\n", dp[P]);
		}
	}
	return 0;
}