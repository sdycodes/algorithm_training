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
	int p, q;
	while(scanf("%d%d", &p, &q)!=EOF){
		printf("%d\n", p+q-gcd(p, q));
	}
}