#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	while(n--){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", a+b);
	}
	return 0;
}