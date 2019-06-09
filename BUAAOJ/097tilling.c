#include <stdio.h>
int main(int argc, char *argv[]) {
	int memo[35];
	memo[1] = 1;
	memo[2] = 3;
	for (int i = 3; i <= 30; i++) {
		memo[i] = 2 * memo[i - 2] + memo[i - 1];
	}
	int N;
	while(scanf("%d", &N) != EOF) {
		printf("%d\n", memo[N]);
	}
	return 0;
}