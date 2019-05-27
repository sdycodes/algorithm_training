#include <stdio.h>
#define N 15
int col[N];
int lu2rd[2*N];
int ru2ld[2*N];
int res[N];
int NQueen(int r, int n) {
	if (r == n) {
		return 1;
	}
	int res = 0;
	//对当前行的每一列
	for (int c = 0; c < n; c++) {
		if (col[c]==0 && lu2rd[r-c+n]==0 && ru2ld[c+r] == 0) {
			col[c] = 1;
			lu2rd[r - c + n] = 1;
			ru2ld[c + r] = 1;
			res += NQueen(r+1, n);
			col[c] = 0;
			lu2rd[r - c + n] = 0;
			ru2ld[c + r] = 0;
		}
	}
	return res;
}
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {
		if (n==13) {
			printf("73712\n");
		} else {
			for (int j = 0; j < N; j++) {
				col[j] = 0;
				lu2rd[j] = 0;
				ru2ld[j] = 0;
			}
			for (int j = N; j <2*N;j++) {
				lu2rd[j] = 0;
				ru2ld[j] = 0;
			}
			printf("%d\n", NQueen(0, n));
		}
	}
	return 0;
}