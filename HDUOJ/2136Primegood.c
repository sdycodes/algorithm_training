#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	int LPF[1000005];
	memset(LPF, 0, sizeof(LPF));
	int pos = 1;
	for(int i=2;i<=1000000;i++){
		if(LPF[i]==0){
			LPF[i] = pos;
			for(int j=i+i;j<=1000000;j+=i){
				LPF[j] = pos;
			}
			pos++;
		}
	}
	int n;
	while(scanf("%d", &n)!=EOF){
		printf("%d\n", LPF[n]);
	}
	
}