#include <stdio.h>
//几何找规律 m + 2(n-1)
int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &m, &n) != EOF) {
		printf("%d\n", m + 2 * n - 2);
	}
	return 0;
}