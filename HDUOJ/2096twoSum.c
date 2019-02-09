#include <stdio.h>

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		int A, B;
		scanf("%d%d", &A, &B);
		printf("%d\n", (A%100+B%100)%100);
	}
}