#include <stdio.h>
#include <string.h>

double dp[10005];
int w[10005];
double p[10005];

double min(double a, double b){
	return a<b?a:b;
}

int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &n, &m)!=EOF&&!(n==0&&m==0)){
		for(int i=0;i<m;i++){
			scanf("%d%lf", &w[i], &p[i]);
			p[i] = 1-p[i];
		}
		for(int i=0;i<=n;i++)
			dp[i] = 1;
		for(int i=0;i<m;i++){
			for(int j=n;j>=0;j--){
				if(j-w[i]>=0)
					dp[j] = min(dp[j], dp[j-w[i]]*p[i]);
			}
		}
		printf("%.1f%%\n", (1-dp[n])*100);
	}
}