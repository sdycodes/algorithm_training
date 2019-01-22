#include <stdio.h>
char s[1005];
int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	getchar();
	while(T--){
		char c;
		int cnt = 0;
		while(scanf("%c", &c)){
			if(c==' '){
				while(cnt--)
					printf("%c", s[cnt]);
				cnt = 0;	//注意while(cnt--)最后结束的时候cnt不是0
				printf(" ");
			}
			else if(c=='\n'){
				while(cnt--)
					printf("%c", s[cnt]);
				cnt = 0;
				printf("\n");
				break;
			}
			else{
				s[cnt++] = c;
			}
		}
	}
}