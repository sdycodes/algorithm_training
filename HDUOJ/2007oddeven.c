#include <stdio.h>
int max(int a, int b){
	return a>b?a:b;
}
int min(int a, int b){
	return a<b?a:b;
}
//小坑 注意交换 给出的数字不一定从小到大
int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &n, &m)!=EOF){
		int a = min(n, m);
		int b = max(n, m);
		int res_even = 0, res_odd = 0;
		for(int i=a;i<=b;i++){
			if(i%2)
				res_odd += i*i*i;
			else
				res_even += i*i;
		}
		printf("%d %d\n", res_even, res_odd);
	}
}