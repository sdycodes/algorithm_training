#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char s[15];
	int days[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	while(scanf("%s", s)!=EOF){
		int len = strlen(s);
		int y = 0, m = 0, d = 0;
		int state = 0;
		for(int i=0;i<len;i++){
			if(s[i]=='/')
				state++;
			else if(state==0)
				y = y*10 + s[i] -'0';
			else if(state==1)
				m = m*10 + s[i] -'0';
			else if(state==2)
				d = d*10 + s[i] -'0';
		}
		int isRun = (y%4==0&&y%100!=0)||y%400==0;
		printf("%d\n", days[m]+d+(isRun&&m>2?1:0));
	}
}