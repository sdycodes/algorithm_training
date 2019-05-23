#include <cstdio>
#define MOD 10007
using namespace std;
int a[205];
int main(int argc, char *argv[]) {
	int n, m;
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i < 205; i += 2) {
		a[i] = (a[i - 2] * i) % MOD;
	}
	for (int i = 4; i < 205; i += 2) {
		a[i] = (a[i - 2] * i) % MOD;
	}
	while(scanf("%d%d", &n, &m) != EOF) {
		int res = 0;
		for (int i = 3; i <= 2 * n + 1; i += 2) {
			res = (res + a[i]) % MOD;
		}
		for (int i = 2; i <= 2 * m; i += 2) {
			res = ((res - a[i]) % MOD + MOD) % MOD;
		}
		printf("%d\n", res);
	}
}