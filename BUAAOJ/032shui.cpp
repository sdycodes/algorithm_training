#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int m, n;
	while(scanf("%d%d", &m, &n)!=EOF) {
		if (m > n) {
			m = m ^ n;
			n = m ^ n;
			m = m ^ n;
		}
		printf("%d %d\n", m, (n-m)/2);
	}
	return 0;
}