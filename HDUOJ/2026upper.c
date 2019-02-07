#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char s[105];
	while(scanf("%[^\n]", s)!=EOF){
		getchar();
		int upper = 1;
		for(int i=0;i<strlen(s);i++){
			if(s[i]==' '){
				printf(" ");
				upper = 1;
			}
			else if(upper==1){
				printf("%c", s[i]-'a'+'A');
				upper = 0;
			}
			else
				printf("%c", s[i]);
		}
		printf("\n");
	}
}