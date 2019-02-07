#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)!=EOF){
		int s = 1;
		for(int i=1;i<n;i++){
			s = (s+1)<<1;
		}
		printf("%d\n", s);
	}
}