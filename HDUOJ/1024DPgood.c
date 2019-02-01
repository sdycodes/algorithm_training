#include <stdio.h>
#include <string.h>
int cur[1000005];
int pre[1000005];
int num[1000005];

#define INT_MIN -2147483648

int max(int a, int b){
	return a>b?a:b;
}

int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &m, &n)!=EOF){
		for(int i=1;i<=n;i++)
			scanf("%d", &num[i]);
		memset(cur, 0, sizeof(cur));
		memset(pre, 0, sizeof(pre));
		int res;
		for(int i=1;i<=m;i++){
			res = INT_MIN;
			for(int j=i;j<=n;j++){
				cur[j] = max(cur[j-1], pre[j-1]) + num[j];
				pre[j-1] = res;
				res = max(res, cur[j]);
			}
		}
		printf("%d\n", res);
	}
}