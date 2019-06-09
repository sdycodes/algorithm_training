#include <stdio.h>
#include <string.h>
#define M 100000000
char s[5005];
char t[5005];
int dp[5005][5005];
int num[5005][5005];
int max(int a, int b) {
	return a > b?a:b;
}
void cal(int lens, int lent) {
	dp[0][0] = 0;
	for (int i = 0; i <= lens; i++) {
		dp[i][0] = 0;
		num[i][0] = 1;
	}
	for (int j = 0; j <= lent; j++) {
		dp[0][j] = 0;
		num[0][j] = 1;
	}
	for (int i = 1; i <= lens; i++) {
		for (int j = 1; j <= lent; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				num[i][j] = num[i - 1][j - 1];
				if (dp[i][j] == dp[i][j - 1]) {
					num[i][j] = (num[i][j] + num[i][j-1]) % M;
				}
				if (dp[i][j] == dp[i - 1][j]) {
					num[i][j] = (num[i][j] + num[i - 1][j]) % M;
				}
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				num[i][j] = 0;
				if (dp[i][j] == dp[i][j - 1]) {
					num[i][j] = (num[i][j] + num[i][j-1]) % M;
				}
				if (dp[i][j] == dp[i - 1][j]) {
					num[i][j] = (num[i][j] + num[i - 1][j]) % M;
				}
				if (dp[i][j] == dp[i - 1][j - 1]) {
					num[i][j] -= num[i - 1][j - 1];
					num[i][j] = (num[i][j] + M) % M;
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	while(scanf("%s", s) != EOF) {
		scanf("%s", t);
		int lens = strlen(s) - 1;
		int lent = strlen(t) - 1;
		cal(lens, lent);
		printf("%d\n%d\n", dp[lens][lent], num[lens][lent]);
	}	
}