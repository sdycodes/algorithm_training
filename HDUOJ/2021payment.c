#include<stdio.h>

int b[6]={100,50,10,5,2,1};
int main(int argc, char *argv[]){
	int n;
	while(scanf("%d",&n)&&n!=0){
		int cnt = 0, tmp;
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			while(tmp!=0){
			   	for(int j=0;j<6;j++){
			   		if(tmp>=b[j]){
						tmp=tmp-b[j];
						cnt++;
						break;
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}