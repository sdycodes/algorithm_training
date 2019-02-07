#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int m, n;
	while(scanf("%d%d", &n,&m)!=EOF){
		int tmp, rx, ry, s = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d", &tmp);
				if(tmp!=-2147483648&&abs(tmp)>abs(s)){
					s = tmp;
					rx = i;
					ry = j;
				}
			}
		}
		printf("%d %d %d\n", rx, ry, s);
	}
}