#include <stdio.h>

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		int sign = 1;
		double res = 0;
		for(int i=1;i<=n;i++){
			res += sign*1.0/i;
			sign *= -1;
		}
		printf("%.2f\n", res);
	}
}