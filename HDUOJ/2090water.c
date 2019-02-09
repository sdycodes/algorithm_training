#include <stdio.h>

int main(int argc, char *argv[]) {
	char s[100];
	double sum =0, quant, price;
	while(scanf("%s%lf%lf", s, &quant, &price)!=EOF){
		sum += quant*price;
	}
	printf("%.1lf\n", sum);
}