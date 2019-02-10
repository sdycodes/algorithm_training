#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	long long m;
	while(scanf("%d%lld", &n, &m)&&!(m==0&&n==0)){
		for(int i=1, pos = 0;pos<64;i=i<<1, pos++){
			if((i&m)!=0){
				printf("%d\n", pos+1);
				break;
			}
		}
	}
}