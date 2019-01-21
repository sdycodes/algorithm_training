#include <stdio.h>

int cal(int n,int m){
	int cnt=0,i,j;
	for(i=1;i<n;i++)
		for(j=i+1;j<n;j++)
		if((i*i+j*j+m)%(i*j)==0 )
		   cnt++;
	return cnt;
}

int main(void){
	int i,N,n,m;
	scanf("%d",&N);
	getchar();
	getchar();
	for(i=0;i<N;i++){       
		if(i!=0)	printf("\n");
		int cnt=1;
		while (scanf("%d%d",&n,&m)==2&&!(n==0&&m==0))
			printf("Case %d: %d\n", cnt++, cal(n,m));
	}
	return 0;
}
