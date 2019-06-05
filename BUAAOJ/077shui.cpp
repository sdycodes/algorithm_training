#include <iostream>
using namespace std;
int gcd (int n, int m) {
	int r = 1;
	while(r) {
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}
int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		if (n > m) {
			n = n ^ m;
			m = n ^ m;
			n = n ^ m;
		}
		if (gcd(n, m) == 1) {
			printf("jhljxshidadoubi\n");
		} else {
			printf("shuishuowoshidadoubi\n");
		}
	}
}