#include <stdio.h>

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		int A, B;
		scanf("%d%d", &A, &B);
		if(A%B==0)	printf("YES\n");
		else printf("NO\n");
	}
}