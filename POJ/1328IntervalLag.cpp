#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct inter{
	double l, r;
}inters[1005];

bool comp(inter a, inter b){
	return a.l<b.l;
}

int covers[1005], cnt;

int main(int argc, char *argv[]) {
	int n, d;
	int cas = 1;
	while(scanf("%d%d", &n, &d)!=EOF&&!(n==0&&d==0)){
		double x, y;
		int res = 0;
		cnt = 0;
		for(int i=0;i<n;i++){
			scanf("%lf%lf", &x, &y);
			if(abs(d)<abs(y)){
				res = -1;
				continue;
			}
			double dx = sqrt(pow((double)d, 2)-pow(y, 2));
			inters[i].l = x - dx;
			inters[i].r = x + dx;
		}
		if(d<0)	res = -1;
		if(res!=-1){
			sort(inters, inters+n, comp);
			res = 1;
			double latest = inters[0].r;
			for(int i=1;i<n;i++){
				if(inters[i].r<latest)
						latest = inters[i].r;
				else if(inters[i].l>latest){
					latest = inters[i].r;
					res++;
				}
			}
		}
		printf("Case %d: %d\n", cas++, res);
	}
}