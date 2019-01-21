#include <cstdio>
#include <algorithm>

using namespace std;
struct JFR{
	int j, f;
	double ratio;
};
JFR T[1005];
bool comp(JFR &a, JFR &b){
	return a.ratio > b.ratio;
}
int main(int argc, char *argv[]) {
	int N, M, i;
	while(scanf("%d%d", &M, &N)&&M!=-1&&N!=-1){
		for(i=0;i<N;i++){
			scanf("%d%d", &(T[i].j), &(T[i].f));
			T[i].ratio = (double)T[i].j/T[i].f;
		}
		sort(T, T+N, comp);
		double tot = 0;
		for(i=0;i<N;i++){
			if(M>=T[i].f){
				tot += T[i].j;
				M-=T[i].f;
			}
			else{
				tot += (T[i].j*((double)M/T[i].f));
				break;
			}
		}
		printf("%.3f\n", tot);
	}
}