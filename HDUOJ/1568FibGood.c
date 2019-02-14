#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]){
	int n;
	int f[21]={0,1};
	double a=(1+sqrt(5))/2;
	for(int i=2;i<21;i++)
		f[i]=f[i-1]+f[i-2];
	while(scanf("%d",&n)!=EOF){
		if(n<21)
			printf("%d\n",f[n]);
		else{
			int answer;
			double ans=-0.5*log10(5.0)+n*log10(a);//对公式求对数
			ans=ans-floor(ans);		//得到ans的小数部分
			ans=pow(10,ans);		//再取一次幂回去，得到形如1.023443198的数，（原数1023443198）
			answer=ans*1000;		//转换成整形自动把小数点后的数舍去，得到前四位
			printf("%d\n",answer);
		}
	}
	return 0;
}