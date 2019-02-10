#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		int n, k;
		scanf("%d%d", &n, &k);
		printf("%lld\n", (long long)pow(2, n-k));
	}
}