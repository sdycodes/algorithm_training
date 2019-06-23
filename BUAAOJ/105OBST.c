//最优二叉查找树
#include <stdio.h>
#define MAXN 30
#define INF 999999
double p[MAXN + 5];
double q[MAXN + 5];

int root[MAXN + 1][MAXN + 1];    //记录根节点
double w[MAXN + 2][MAXN + 2];    
double e[MAXN + 2][MAXN + 2];    //子树期望代价

//子树各个节点概率和，因为从下往上构造的时候会多一层，期望会增加w[i][j]
//减少了计算成本
//这道题还有一个值得学习的地方，使用[i][i-1]表示查找失败的情况 很聪明
double OBST(double p[], double q[], int n) {
	//initialize
	for(int i = 1; i <= n + 1; i++){
		e[i][i - 1] = q[i - 1];
		w[i][i - 1] = q[i - 1];
	}
	//dp
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			e[i][j] = INF;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			//求取最小代价的子树的根
			for (int r = i; r <= j; r++) {
				double temp = e[i][r - 1] + e[r + 1][j] + w[i][j];
				if (temp < e[i][j]) {
					e[i][j] = temp;
					root[i][j] = r;
				}
			}
		}
	}
	return e[1][n];
}

int main(int argc, char * argv[]) {
	int N;
	while(scanf("%d", &N) != EOF) {
		p[0] = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%lf", &p[i]);
		}
		for (int i = 0; i < N + 1; i++) {
			scanf("%lf", &q[i]);
		}
		printf("%.3lf\n", OBST(p, q, N));
	}
	return 0;
}