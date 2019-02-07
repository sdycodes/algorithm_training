#include <stdio.h>

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		getchar();
		char c;
		scanf("%c", &c);
		int a, b;
		scanf("%d%d", &a, &b);
		if(c=='+')	printf("%d\n", a+b);
		else if(c=='-') printf("%d\n", a-b);
		else if(c=='*') printf("%d\n", a*b);
		else if(a%b!=0)	printf("%.2f\n", (double)a/b);
		else printf("%d\n", a/b);
	}
}