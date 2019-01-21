#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;
struct point{
	double x, y;
};

point p[100005];
point pt[100005];

bool comp(point &a, point &b){
	return a.x < b.x;
}

double dist(point a, point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double min_dist(int begin, int end){
	//trival
	if(end-begin<=0)
		return (double)INT_MAX;
	if(end-begin==1){
		point t;
		if(p[begin].y>p[end].y){
			t = p[begin];
			p[begin] = p[end];
			p[end] = t;
		}
		return dist(p[begin], p[end]);	
	}
	//divide
	int mid = (begin+end)>>1;	//记录中间点
	double cut = p[mid].x;		//记录中间位置
	double min_d = min(min_dist(begin, mid), min_dist(mid+1, end));
	
	//merge 按y排序
	int l = begin, r = mid+1, t=begin;
	while(l<=mid&&r<=end){
		if(p[l].y<p[r].y)
			pt[t++] = p[l++];	
		else
			pt[t++] = p[r++];	
	}
	while(l<=mid)
		pt[t++] = p[l++];
	while(r<=end)
		pt[t++] = p[r++];	
	for(t=begin;t<=end;t++)
		p[t] = pt[t];
		
	
	point * tmps = (point*)malloc(sizeof(point)*(end-begin+1));
	int cnt=0, i, j;
	//检查所有中间待计算点 注意这里必须这样检查 因为p已经按y排序了 所以不再按x排序
	for(i=begin;i<=end;i++){
		if(fabs(p[i].x-cut)<=min_d){
			tmps[cnt++] = p[i];
		}
	}
	//计算最小距离 最多6个点
	for(i=0;i<cnt;i++){
		for(j=i+1;j<cnt&&j<i+7;j++){
			min_d = min(min_d, dist(tmps[i], tmps[j]) );
		}
	}
	free(tmps);
	return min_d;
}


int main(int argc, char *argv[]) {
	int N;
	double dist;
	while(scanf("%d", &N)&&N!=0){
		for(int i=0;i<N;i++)
			scanf("%lf %lf", &(p[i].x), &(p[i].y));
		sort(p, p+N, comp);
		dist = min_dist(0, N-1);
		printf("%.2f\n", dist/2.0);
	}	
	return 0;
}
