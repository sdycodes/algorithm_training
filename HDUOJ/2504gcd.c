#include <stdio.h>
int gcd(int a, int b){
	if(a<b){
		int t = a;
		a = b;
		b = t;
	}
	while(b){
		int t = a;
		a = b;
		b = t%b;
	}
	return a;
}
int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		int a, b, c;
		scanf("%d%d", &a, &b);
		if(a==b){
			printf("%d\n", 2*b);
			continue;
		}
		for(c=b+b;c<a;c+=b){
			if(gcd(a, c)==b){
				printf("%d\n", c);
				break;
			}
		}
	}
}