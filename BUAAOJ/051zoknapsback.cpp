#include <cstdio>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
	int dp[20005], T, k;
	int t[305], v[305];
	while(scanf("%d%d", &T, &k) != EOF) {
		for (int i = 1; i <= k; i++) {
			scanf("%d%d", &v[i], &t[i]);
		}
		for (int j = 0; j <= T; j++) {
			dp[j] =  (j >= t[1])? v[1] : 0;
		}
		for (int i = 2; i <= k; i++) {
			for (int j = T; j >= t[i]; j--) {
				dp[j] = (dp[j] > dp[j - t[i]] + v[i])? dp[j]: (dp[j - t[i]] + v[i]); 
			}
		}
		printf("%d\n", dp[T]);
	}
}