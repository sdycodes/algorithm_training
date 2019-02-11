#include <stdio.h>
#include <stdlib.h>

//这个题诸多问题  单位错误、涵义不明确
//简单说 求两个分数的最小公倍数
//操作方法 通分 对分子求最小公倍数 然后约分即可
long long gcd(long long a, long long b){
	if(a<b){
		long long t = a;
		a = b;
		b = t;
	}
	while(b){
		long long t = a;
		a = b;
		b = t%b;
	}
	return a;
}

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--){
		//get all numbers
		long long a1, a2, b1, b2;
		scanf("%lld/%lld %lld/%lld", &a1, &a2, &b1, &b2);
		//process
		//s1 通分
		int tmp = gcd(a2, b2);
		long long c2 = a2*(b2/tmp);
		a1 *= (b2/tmp);
		b1 *= (a2/tmp);
		//s2 通分后的分子求最小公倍数得到分子
		long long c1 = a1*(b1/gcd(a1, b1));
		//s3 约分
		tmp = gcd(c1, c2);
		c1 /= tmp;
		c2 /= tmp;
		//s3 输出时判定 分母是否为1
		if(c2!=1)
			printf("%lld/%lld\n", c1, c2);
		else
			printf("%lld\n", c1);
	}
}