#include <stdio.h>

int main(int argc, char *argv[]) {
	int N;
	int temp, pre, tot;
	while(scanf("%d", &N)&&N!=0){
		pre = 0;
		tot = 0;
		for(int i=0;i<N;i++){
			scanf("%d", &temp);
			if(temp-pre>0)
				tot += (6*(temp-pre)+5);
			else if(temp-pre<0)
				tot+= (4*(pre-temp)+5);
			else 
				tot+=5;
			pre = temp;
		}
		printf("%d\n", tot);
	}
}