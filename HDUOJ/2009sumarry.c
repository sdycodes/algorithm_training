#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &n, &m)!=EOF){
		double res = 0;
		double tmp = n;
		int i=0;
		while(i<m){
			res += tmp;
			tmp = sqrt(tmp);
			i++;
		}
		printf("%.2lf\n", res);
	}
}