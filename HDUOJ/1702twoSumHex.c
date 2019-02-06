#include <stdio.h>

int main(int argc, char *argv[]) {
	int a, b;
	while(scanf("%x%x", &a, &b)!=EOF){
		printf("%d\n", a+b);
	}
}