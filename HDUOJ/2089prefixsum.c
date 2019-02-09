#include <stdio.h>

//应用前缀和
//使用打表策略，学名在线离线
//注意digits的顺序是反的
//更快捷 string.h中的strstr(a, b)判断b是否为a的字串 是返回第一次匹配的地址 否则NULL
int res[1000001];
int main(int argc, char *argv[]) {
	int n, m;
	int digits[10];
	int pos;
	res[0] = 0;
	for(int i=1;i<=1000000;i++){
		pos = 0;
		int r = i;
		do{
			digits[pos++] = r%10;
			r /= 10;
		}while(r);
		int can = 1;
		for(int j=0;j<pos;j++){
			if(digits[j]==4||(j>=1&&digits[j-1]==2&&digits[j]==6)){
				can = 0;
				break;
			}
		}
		if(can) res[i] = res[i-1]+1;
		else res[i] = res[i-1];
	}
	while(scanf("%d%d", &n, &m)&&!(n==0&&m==0)){
		printf("%d\n", res[m]-(n==0?0:res[n-1]));
	}
}