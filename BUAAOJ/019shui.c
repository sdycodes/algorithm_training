#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	printf("%d", n%3==0?n/3:n/3+1);
}