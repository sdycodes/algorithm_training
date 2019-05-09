#include <iostream>
#include <cstdlib>
#include <cstdio>

#define MOD 1000007
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	int *p;
	while(scanf("%d", &n) != EOF) {
		p = (int*)malloc(sizeof(int)*(n+1));
		int x;
		scanf("%d", &x);
		int res = 0;
		for (int i = 0; i < n + 1; i++) {
			scanf("%d", p + n - i);
		}
		for (int i = 0; i <= n; i++) {
			res = (( ((res % MOD) * (x % MOD)) + p[i]) % MOD);
		}
		printf("%d\n", res);
	}
}