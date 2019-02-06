#include <stdio.h>
int recs[1000];
int main(int argc, char *argv[]) {
	int m, n;
	while(scanf("%d%d", &m, &n)!=EOF){
		int cnt = 0;
		for(int i=m;i<=n;i++){
			int tmp = 0;
			int rec= i;
			while(rec){
				tmp += ((rec%10)*(rec%10)*(rec%10));
				rec /= 10;
			}
			if(tmp==i)
				recs[cnt++] = i;
		}
		if(cnt==0)	printf("no\n");
		else{
			for(int j=0;j<cnt-1;j++){
				printf("%d ", recs[j]);
			}
			printf("%d\n", recs[cnt-1]);
		}
	}
}