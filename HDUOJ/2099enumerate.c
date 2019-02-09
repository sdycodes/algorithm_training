#include <stdio.h>

int main(int argc, char *argv[]) {
	int a, b;
	int ans[105], pos;
	while (scanf("%d%d", &a, &b)&&!(a==0&&b==0)) {
		pos = 0;
		for(int i=0;i<=99;i++){
			if((a*100+i)%b==0)	ans[pos++] = i;
		}
		for(int i=0;i<pos-1;i++)
			printf("%02d ", ans[i]);
		printf("%02d\n", ans[pos-1]);
	}
}