#include <cstdio>
using namespace std;
int gcd(int n, int m) {
	if (n > m) {
		n = n ^ m;
		m = n ^ m;
		n = n ^ m;
	}
	int r = 1;
	while(r) {
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}
int main(int argc, char *argv[]) {
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF) {
		int f = gcd(a, b);
		printf("%d\n", a / f * b);
		
	}
}