#include <stdio.h>

int main(int argc, char *argv[]) {
	double sum = 0;
	double tmp;
	while(scanf("%lf", &tmp)!=EOF){
		sum += tmp;
	}
	double avg = sum /12.0;
	printf("$%.2f\n", avg);
}