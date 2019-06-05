#include <stdio.h>

int gcd(int a, int b) {
	int r = 1;
	while(r) {
		r = b % a;
		b = a;
		a = r;
	}
	return b;
}
int main(int argc, char *argv[]) {
	int m, n;
	while(scanf("%d%d", &m, &n)!= EOF) {
		int integer = m / n;
		int rem = m % n;
		if (rem == 0) {
			printf("%d\n", integer);
		} else {
			int g = gcd(rem, n);
			printf("%d+%d/%d\n", integer, rem/g, n/g);
		}
	}
}