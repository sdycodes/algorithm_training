#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)!=EOF){
		double maxScore = 0, minScore = 200;
		double sum = 0, tmp;
		for(int i=0;i<n;i++){
			scanf("%lf", &tmp);
			sum += tmp;
			if(tmp>maxScore)	maxScore = tmp;
			if(tmp<minScore)	minScore = tmp;
		}
		printf("%.2f\n", (sum-maxScore-minScore)/(n-2));
	}
}