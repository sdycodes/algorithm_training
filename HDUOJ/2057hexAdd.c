#include <stdio.h>
int main(int argc, char *argv[]){
	long long a,b,c;
	while(scanf("%I64X %I64X",&a,&b)!=EOF){
		c=a+b;
		if(c<0)
			printf("-%I64X\n",-c);
		else
			printf("%I64X\n",c);
	}
	return 0;
}