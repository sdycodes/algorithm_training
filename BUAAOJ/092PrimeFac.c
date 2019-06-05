#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for (int i = 2; i <= n; i++) {
			while (n != i) {
				if (n % i == 0) {
					printf("%d*", i);
					n /= i;
				} else {
					break;
				}
			}
		}
		printf("%d\n", n);
	}
}