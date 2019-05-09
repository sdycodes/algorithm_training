#include <stdio.h>

int main() {
	int n, a, b, c;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d%d", &a, &b, &c);
		if (a > b && b <= c) {
			printf("fail\n");
		} else if (b >= a) {
			printf("1\n");
		} else {
			printf("%d\n",((a - b) % (b - c)==0?(a - b) / (b - c): ((a - b) / (b - c) + 1))+ 1);
		}
	}
}