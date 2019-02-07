#include <stdio.h>
#include <string.h>
#include <ctype.h> 
int main(int argc, char *argv[]) {
	char s[100];
	int T;
	scanf("%d", &T);
	
	while(T--){
		getchar();
		scanf("%[^\n]", s);
		int len = strlen(s);
		if(!(s[0]=='_'||isalpha(s[0]))){
			printf("no\n");
			continue;
		}
		int i;
		for(i=1;i<len;i++){
			if(!(isalnum(s[i])||s[i]=='_')){
				printf("no\n");
				break;
			}
		}
		if(i==len)	printf("yes\n");
	}
}