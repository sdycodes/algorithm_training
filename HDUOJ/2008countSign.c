#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)!=EOF){
		if(n==0)	break;
		int pos = 0, neg = 0, zero = 0;
		double f;
		for(int i=0;i<n;i++){
			scanf("%lf", &f);
			if(f>0.0000000001)	pos++;
			else if(f<-0.000000001)	neg++;
			else zero++;
		}
		printf("%d %d %d\n", neg, zero, pos);
	}
}