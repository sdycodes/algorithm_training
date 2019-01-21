#include <stdio.h>
#include <string.h>
char s[10005];
int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		char c = s[0];
		int cnt = 1;
		int i = 1;
		while(i<strlen(s)){
			if(s[i]==c)	cnt++;
			else{
				if(cnt==1)	printf("%c", c);
				else	printf("%d%c", cnt, c);
				cnt = 1;
				c = s[i];
			}
			i++;
		}
		if(cnt==1)	printf("%c\n", c);
		else	printf("%d%c\n", cnt, c);
	}
	return 0;	
}