#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		int res = 1;
		for (int i = 2; i < (int)sqrt(n) + 1; i++) {
			if (n % i == 0) {
				if (i >= n / i) {
					res += i;
				} else {
					res += (i + n / i);
				}
			}
		}
		printf("%d\n", res);
	}
}