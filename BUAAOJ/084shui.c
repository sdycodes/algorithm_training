#include <stdio.h>
#include <math.h>

int isPrime(int n) {
	if (n <= 3) {
		return (n - 1 > 0)?1:0;
	}
	if (n % 6 != 1 && n % 6 != 5) {
		return 0;
	}
	for (int i = 5; i < (int)sqrt(n) + 1; i += 6) {
		if (n %  i == 0|| n % (i + 2) == 0) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		if (!isPrime(m)) {
			printf("I choose go die\n");
			continue;
		}
		long long res = 0;
		while(n) {
			n /= m;
			res += n;
		}
		printf("%lld\n", res);
	}
}