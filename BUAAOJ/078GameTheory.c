#include <stdio.h>
int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		if (n > m) {
			int t = n;
			n = m;
			m = t;
		}
		if (n % 2) {
			printf("jhljx\n");
		} else {
			printf("KamuiKirito\n");
		}
	}
	return 0;
}