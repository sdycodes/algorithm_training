#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		printf("%lld\n", (long long)pow(3, n));
	}
}