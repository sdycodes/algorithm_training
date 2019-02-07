#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	int T;
	char s[105];
	scanf("%d", &T);
	while(T--){
		getchar();
		int a = 0, e = 0, i2 = 0, o = 0, u = 0;
		scanf("%[^\n]", s);
		for(int i=0;i<strlen(s);i++){
			if(s[i]=='a'||s[i]=='A')	a++;
			else if(s[i]=='e'||s[i]=='E')	e++;
			else if(s[i]=='i'||s[i]=='I')	i2++;
			else if(s[i]=='o'||s[i]=='O')	o++;
			else if(s[i]=='u'||s[i]=='U')	u++;
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", a, e, i2, o, u);
		if(T!=0)	printf("\n");
	}
}