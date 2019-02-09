#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)&&n!=0){
		int s10 = 0, s12 = 0, s16 = 0;
		int r = n;
		do{
			s10 += (r%10);
			r /= 10;
		}while(r);
		r = n;
		do{
			s12 += (r%12);
			r /= 12;
		}while(r);
		r = n;
		do{
			s16 += (r%16);
			r /= 16;
		}while(r);
		if(s10==s12&&s12==s16)
			printf("%d is a Sky Number.\n", n);
		else
			printf("%d is not a Sky Number.\n", n);
	}
}