#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
double * cal_two(int a1, int b1, int c1, int a2, int b2, int c2) {
	double * res = NULL;
	if ((a1 == 0 && b1 == 0) || (a2 == 0 && b2 == 0)) {
		//有直线不存在
		return res;
	} else if (a1 * b2 == a2 * b1) {
		//直线平行
		return res;
	} else {
		//一般情况
		res = (double*)malloc(sizeof(double)*2);
		res[0] = (double)(b1*c2 - b2*c1) / (a1*b2 - a2*b1);
		res[1] = (double)(a2*c1 - a1*c2) / (a1*b2 - a2*b1);
	}
	return res;
}
int main(int argc, char *argv[]) {
	int a[9];
	while(scanf("%d%d%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8])!=EOF) {
		// 求解
		double ** reses = (double**)malloc(sizeof(double*)*3);
		reses[0] = cal_two(a[0], a[1], a[2], a[3], a[4], a[5]);
		reses[1] = cal_two(a[0], a[1], a[2], a[6], a[7], a[8]);
		reses[2] = cal_two(a[3], a[4], a[5], a[6], a[7], a[8]);
		int no_dup[3] = {-1, -1, -1};
		int cnt = 0;
		// 去重
		for (int i = 0; i < 3; i++) {
			if (reses[i] != NULL) {
				int j;
				for (j = 0; j < cnt; j++) {
					if (!(reses[no_dup[j]][0] == reses[i][0] && reses[no_dup[j]][1] == reses[i][1])) {
						continue;
					} else {
						break;
					}
				}
				if (j == cnt) {
					no_dup[cnt++] = i;
				}
			}
		}

		// 排序
		for (int i = 0; i < cnt; i++) {
			for (int j = i+1; j < cnt; j++) {
				if (reses[no_dup[i]][0] - reses[no_dup[j]][0] > 0.00001) {
					int tmp = no_dup[i];
					no_dup[i] = no_dup[j];
					no_dup[j] = tmp;
				} else if (fabs(reses[no_dup[i]][0] - reses[no_dup[j]][0]) < 0.00001) {
					if (reses[no_dup[i]][1] - reses[no_dup[j]][1] > 0.00001) {
						int tmp = no_dup[i];
						no_dup[i] = no_dup[j];
						no_dup[j] = tmp;
					}
				}
			}
		}
		// 输出
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; i++) {
			double a = fabs(reses[no_dup[i]][0]) < 0.001? 0.0: reses[no_dup[i]][0];
			double b = fabs(reses[no_dup[i]][1]) < 0.001? 0.0: reses[no_dup[i]][1];
			printf("%.2f %.2f\n", a, b);
		}
	}
	return 0;
}