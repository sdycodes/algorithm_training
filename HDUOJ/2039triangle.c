#include <stdio.h>

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	double a, b, c;
	while(T--){
		scanf("%lf%lf%lf", &a, &b, &c);
		if(a+b>c&&a+c>b&&b+c>a)
			printf("YES\n");
		else
			printf("NO\n");
	}
}