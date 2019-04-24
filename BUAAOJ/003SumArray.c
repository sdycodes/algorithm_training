#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, m,k;
	while(scanf("%d%d%d", &n, &m, &k)!=EOF){
		printf("%d\n", (k+1)*(2*n+k*m)>>1);
	}
	return 0;
}