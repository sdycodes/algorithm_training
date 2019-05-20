#include <cstdio>
#include <cstring>
#define MEMOSIZE 1000000
//数据范围
//记忆化
using namespace std;

long long memo[MEMOSIZE];
int main(int argc, char *argv[]) {
	long long n;
	memset(memo, -1, sizeof(memo));
	while(scanf("%lld", &n) != EOF) {
		long long rn = n;
		long long rnd = 0;
		while(n != 1) {
			//printf("%d\n", n);
			if (n < MEMOSIZE && memo[n]!=-1) {
				if (rn < MEMOSIZE) {
					memo[rn] = rnd + memo[n];
					printf("%lld\n", memo[rn]);
				} else {
					printf("%lld\n", memo[n] + rnd);
				}
				break;
			}
			if (n%2==0) {
				n /= 2;
			} else {
				n = 3 * n + 1;
			}
			rnd++;
		}
		printf("%lld\n", rnd);
	}
}