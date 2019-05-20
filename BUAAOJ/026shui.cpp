#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	int x0, y0, z0;
	while(scanf("%d%d%d", &x0, &y0, &z0) != EOF) {
		int n;
		int maxdis = -1;
		int recidx = -1;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x1, y1, z1;
			scanf("%d%d%d", &x1, &y1, &z1);
			int dis = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) + (z1 - z0) * (z1 - z0);
			if (maxdis == - 1 || maxdis < dis) {
				maxdis = dis;
				recidx = i;
			}
		}
		int k;
		scanf("%d", &k);
		printf("%d %.6f\n", recidx + 1, 2 * sqrt(maxdis) * k);
	}
}