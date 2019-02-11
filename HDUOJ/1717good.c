#include <stdio.h>
#include <string.h>

long long gcd(long a, long b){
	//a > b guaranteed from passing para
	while(b){
		long long t = a;
		a = b;
		b = t%b;
	}
	return a;
}
//小数化分数
//1 有限小数 用10000凑 约分
//2 无限循环小数  设不循环的位数为m 循环位数为n
//（前m+n位-前m位）/n个9m个0
int main(int argc, char *argv[]) {
	int T;
	char s[30];
	char fin[10];
	char inf[10];
	scanf("%d", &T);
	getchar();
	while(T--){
		scanf("%s", s);
		int m = 0, n = 0, i = 2;
		while(i<strlen(s)&&s[i]!='(')
			fin[m++] = s[i++];
		if(i<strlen(s)){
			i++;
			while(s[i]!=')')
				inf[n++] = s[i++];
		}
		//计算分母 循环节位数个9分循环节位数个0
		long long denominator = 1;
		int j = 0;
		while(j<m){
			denominator *= 10;
			j++;
		}
		j = 0;
		int rec;
		while(j<n){
			if(j==0){
				denominator *= 9;
				rec = denominator;
			}
			else
				denominator = denominator*10 + rec;
			j++;
		}
		//计算分子 前m+n位-前m位
		long long numerator = 0;
		j = 0;
		while(j<m)
			numerator = numerator*10 + fin[j++]-'0';
		rec = numerator;
		j = 0;
		while(j<n)
			numerator = numerator*10 + inf[j++]-'0';
		if(n)
			numerator -= rec;
		long long tmp = gcd(denominator, numerator);
		printf("%lld/%lld\n", numerator/tmp, denominator/tmp);
		
	}	
}