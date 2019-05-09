#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAXN 1000005
using namespace std;
int a[MAXN];
//注意结果是 long long
//注意merge第二阶段不用再增加逆序数
//注意归并排序最后复制回去数组下标
//注意归并排序最后复制在while循环之外还有一个
long long merge(int low, int high) {
	if (low == high) {
		return 0;
	}
	long long res = 0;
	int mid = (low+high) >> 1;
	res += merge(low, mid);
	res += merge(mid+1, high);
	int *tmp = (int*)malloc(sizeof(int)*(high-low+1));
	int lp = low, rp = mid+1;
	int k = 0;
	while(lp <= mid && rp <= high) {
		if (a[lp] <= a[rp]) {
			tmp[k++] = a[lp++];
		} else {
			tmp[k++] = a[rp++];
			res += (mid - lp + 1);
		}
	}
	while(lp <= mid) {
		tmp[k++] = a[lp++];
		// res += (high - mid);
	}
	while(rp <= high) {
		tmp[k++] = a[rp++];
	}
	while(--k) {
		a[low + k] = tmp[k];
	}
	a[low] = tmp[0];
	return res;
}

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n)!=EOF) {
		for (int i = 0; i <n ;i++) {
			scanf("%d", &a[i]);
		}
		printf("%lld\n", merge(0, n-1));
	}
	return 0;
}