#include <stdio.h>
#include <string.h>

//scanf 读取一行的方法%[]匹配一个集合 遇到\n停止 所以不包含\n 注意getchar
int main(int argc, char *argv[]) {
	char s[300];
	while(scanf("%[^\n]", s)&&!(strlen(s)==1&&s[0]=='#')){
		getchar();
		int sum = 0;
		for(int i=0;i<strlen(s);i++){
			if(s[i]!=' ')
				sum += (i+1)*(s[i]-'A'+1);
		}
		printf("%d\n", sum);
	}
	return 0;
}