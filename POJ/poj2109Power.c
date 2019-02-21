#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
	double n, p;
	while(scanf("%lf%lf", &n, &p)!=EOF)	
		printf("%d\n", (int)floor(pow(p, 1.0/n)+0.5));
}