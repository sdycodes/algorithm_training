#include<stdio.h>

int main(int argc, char *argv[]){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d%d",&a,&b);
		int c=a,d=b;
		for(int i=1;i<a;i++) 
			if(a%i==0) d-=i;
		for(int i=1;i<b;i++) 
			if(b%i==0) c-=i;
		if(c==0&&d==0)
			printf("YES\n");
		else 
			printf("NO\n");
	}
}