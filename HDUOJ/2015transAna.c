#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &n, &m)!=EOF){
		int i = 1;
		for(;i+m-1<n;i+=m){
			printf("%d ", 2*i+m-1);
		}
		printf("%d\n", n+i);
	}
}