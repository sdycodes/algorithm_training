#include <stdio.h>
#include <math.h>

//数位相关的问题可以考虑 10^d = n!
//math库中有log10  log2  返回值是double
//d = log10(n!) = sum(log10(i))上取整

int main(int argc, char *argv[]) {
	int n, num;
	double sum;

	scanf("%d", &n);
	for(int i=0;i<n;i++){
		sum = 0;
		scanf("%d", &num);
		for(int j=1;j<=num;j++)
			sum += log10((float)j);
		printf("%d\n", (int)sum+1);
	}
}