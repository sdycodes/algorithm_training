#include <stdio.h>

int main(int argc, char *argv[]) {
	char c;
	int cnt = 0;
	while(scanf("%c", &c)&&c!='@'){
		cnt++;
		if(cnt!=1)	printf("\n");
		int h;
		scanf("%d", &h);
		getchar();
		for(int i=0;i<h;i++){
			if(i==0){
				for(int j=0;j<h-1;j++)
					printf(" ");
				printf("%c\n", c);
			}
			else if(i==h-1){
				for(int j=0;j<2*h-1;j++)
					printf("%c", c);
				printf("\n");
			}
			else{
				for(int j=0;j<h-1-i;j++)
					printf(" ");
				printf("%c", c);
				for(int j=0;j<2*i-1;j++)
					printf(" ");
				printf("%c\n", c);
			}
		}
	}
}