#include <stdio.h>

//LIS的nlogn方法 比较直观 关键是看出转化
//单数复数输出不一样。。。。。
int r[500005];
int n;
int b_search(int tar, int stack[], int beg, int end){
	while(beg<end){
		int mid = (beg+end)>>1;
		if(stack[mid]<tar)
			beg = mid+1;
		else
			end = mid;
	}
	return end;
}
int LIS(void){
	int stack[500005];
	stack[0] = -1;
	int sp = 0;
	int i = 1;
	while(i<=n){
		if(stack[sp]<r[i])
			stack[++sp] = r[i];
		else
			stack[b_search(r[i], stack, 1, sp)] = r[i];
		i++;
	}
	return sp;
}
int main(int argc, char *argv[]) {
	int cas = 0;
	while(scanf("%d", &n)!=EOF){
		cas++;
		int a, b;
		for(int i=0;i<n;i++){
			scanf("%d%d", &a, &b);
			r[a] = b;
		}
		int res = LIS();
		if(res==1)
			printf("Case %d:\nMy king, at most %d road can be built.\n\n", cas, res);
		else
			printf("Case %d:\nMy king, at most %d roads can be built.\n\n", cas, res);
	}
}