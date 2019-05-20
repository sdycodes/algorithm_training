#include <iostream>

using namespace std;
int gcd(int a, int b) {
	if (a > b) {
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	int r = 1;
	while(r) {
		r = b % a;
		b = a;
		a = r;
	}
	return b;
}

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while (T--) {
		int  a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int upper = a * d + b *c;
		int bottom = b * d;
		int fac = gcd(upper, bottom);
		printf("%d %d\n", upper / fac, bottom / fac);
	}	
	return 0;
}