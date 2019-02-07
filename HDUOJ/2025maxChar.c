#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char s[105];
	while(scanf("%s", s)!=EOF){
		char maxChar = 0;
		for(int i=0;i<strlen(s);i++){
			if(s[i]>maxChar){
				maxChar = s[i];
			}
		}
		for(int i=0;i<strlen(s);i++){
			printf("%c", s[i]);
			if(s[i]==maxChar)
				printf("(max)");
		}
		printf("\n");
	}
}