#include <stdio.h>
#include <ctype.h>
int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	getchar();
	while(T--){
		char tc;
		int cnt = 0;
		while (scanf("%c", &tc)&&tc!='\n')
			if(isdigit(tc))
				cnt++;
		printf("%d\n", cnt);
	}
}