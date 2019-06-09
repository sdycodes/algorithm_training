#include <stdio.h>

int main(int argc, char *argv[]) {
	int C;
	scanf("%d", &C);
	while(C--) {
		int n;
		scanf("%d", &n);
		int a = -1, b = -1, c = -1;
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp <= a|| a == -1) {
				c = b;
				b = a;
				a = tmp;
			} else if (tmp <= b || b == -1) {
				c = b;
				b = tmp;
			} else if (tmp <= c || c == -1) {
				c = tmp;
			}
		}
		printf("%d\n", c);
	}
}