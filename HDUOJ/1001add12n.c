#include <stdio.h>
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)!=EOF){
		if(n%2==0)	printf("%d\n\n", (n>>1)*(n+1));
		else printf("%d\n\n", n*((n+1)>>1));
	}
	return 0;
}