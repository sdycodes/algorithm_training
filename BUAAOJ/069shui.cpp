#include <cstdio>
using namespace std;
int gcd(int x, int y) {
	int r = 1;
	while(r) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
int main(int argc, char *argv[]) {
	int x, y;
	while(scanf("%d%d", &x, &y) != EOF) {
		if (x < y) {
			x = x ^ y;
			y = x ^ y;
			x = x ^ y;
		}
		int d = gcd(x, y);
		printf("%lld\n", (long long) x / d * y);
	}
}