#include<stdio.h>
int main() {
	double a[5][50];
	double c[5];
	int n,m,sum;
	double avg,g_avg;
	while (scanf("%d%d", &n,&m) != EOF) {
		sum = 0; int b[50] = {0};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%lf", &a[j][i]);
			}
		}
		for (int i = 0; i < n; i++) {
			avg = 0;
			for (int j = 0; j < m; j++) {
				avg = avg + a[j][i];
			}
			printf("%.2f", avg / m);
			if (i != n - 1){
				printf(" ");
			}
			else {
				printf("\n");
			}
		}
		int k;
		for (k = 0; k < m; k++) {
			g_avg = 0;
			for (int j = 0; j < n; j++) {
				g_avg = g_avg + a[k][j];
			}
			c[k] = g_avg/n;
			printf("%.2f", g_avg / n);
			if (k != m - 1) {
				printf(" ");
			}
			else {
				printf("\n");
			}
			for (int i = 0; i < n; i++) {
				if (a[k][i] >= c[k]) {
					b[i]++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (b[i] == m) {
				sum++;
			}
		}
		printf("%d\n\n", sum);
	}
	return 0;
}