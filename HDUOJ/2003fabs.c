#include <stdio.h>

int main(int argc, char *argv[]) {
	double f;
	while(scanf("%lf", &f)!=EOF)
		printf("%.2f\n", f>-0.0000001?f:-f);
	return 0;
}