#include <stdio.h>

int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &n, &m)&&!(m==0&&n==0)){
		int sign = 1;
		if(m<0){
			sign = -1;
			m *= -1;
		}
		if(m==0){
			printf("Yes\n");
			continue;
		}
		int no = 1;
		for(int i=1;i<=m/2+1;i++){
			if(m%i==0){
				int j = m/i;
				if((sign==-1&&(i-j==n||j-i==n))||
					(sign==1&&(i+j==n||-i-j==n))){
					printf("Yes\n");
					no = 0;
					break;
				}
			}
		}
		if(no) printf("No\n");
	}
}