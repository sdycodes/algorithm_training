#include <stdio.h>
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%d\n", 2 + 3*n*(n-1));
	}
}