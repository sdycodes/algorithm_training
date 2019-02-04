#include <iostream>
#include <cstring>
using namespace std;
int nf[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int a[1000];
int n, m;
//发现了递归的特征  但是这些小数字算到死。。。
void perm(int m){
	if(m==1){
		for(int i=0;i<n-1;i++)
			printf("%d ", a[i]);
		printf("%d\n", a[n-1]);
		return;
	}
	int len=0;
	while(len<=9&&nf[len]<m)
		len++;
	int group_num = (m+nf[len-1]-1)/nf[len-1];	//算出这个位置上应该是第几个大	
	int tmp = a[n-len+group_num-1];
	int j;
	for(j=n-len+group_num-1;j>n-len;j--)
		a[j] = a[j-1];
	a[j] = tmp;
	perm(m-(group_num-1)*nf[len-1]);
	return;
}

int main(int argc, char *argv[]) {
	
	while(scanf("%d%d", &n, &m)!=EOF){
		for(int i=0;i<n;i++)
			a[i] = i+1;
		perm(m);
	}
	return 0;
}