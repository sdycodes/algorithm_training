#include <stdio.h>

int main(int argc, char *argv[]) {
	int dig[500];
	int pos;
	int N, R;
	while(scanf("%d%d", &N, &R)!=EOF){
		pos = 0;
		int sign = N>=0?1:-1;
		N *= sign;
		while(N){
			dig[pos++] = N%R;
			N /= R;
		}
		if(sign==-1)	printf("-");
		for(int i=pos-1;i>=0;i--)
			printf("%c", dig[i]>=10?(dig[i]-10+'A'):(dig[i]+'0'));
		printf("\n");
	}
}