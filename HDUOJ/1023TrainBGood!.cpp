#include <cstdio>
#include <cstring>
#include <iostream>

//成就
//1 动态规划  不是千篇一律的卡catlan数  自己发现规律
//2 大自然数模板类  重载 << + =运算符  构造函数
using namespace std;
class BigN{
	public:
		int val[100];
		int range;
		BigN(int a){
			val[0] = a;
			range = 1;
		}
		BigN(void){}
	BigN operator+(const BigN b){
		BigN res(0);
		int flag = 0;
		int small = this->range<b.range?this->range:b.range;
		int big = this->range>=b.range?this->range:b.range;
		int i = 0;
		for(;i<small;i++){
			res.val[i] = (this->val[i]+b.val[i]+flag)%1000;
			flag = (this->val[i]+b.val[i]+flag)/1000;
		}
		for(;i<big;i++){
			if(big==b.range){
				res.val[i] = (b.val[i]+flag)%1000;
				flag = (b.val[i]+flag)/1000;
			}
			else{
				res.val[i] = (this->val[i]+flag)%1000;
				flag = (this->val[i]+flag)/1000;
			}
		}
		res.val[i] = flag;
		res.range = flag>0?big+1:big;
		return res;
	}
	
	BigN operator*(const BigN b){
		BigN res(0);
		int tmp;
		memset(res.val, 0, sizeof(res.val));
		int flag = 0;
		for(int i=0;i<this->range;i++){
			if(this->val[i]==0) continue;
			for(int j=0;j<b.range;j++){
				tmp = res.val[i+j] + (flag+this->val[i]*b.val[j]);
				res.val[i+j] = tmp%1000;
				flag = tmp/1000;
			}
			res.val[i+b.range] = flag;
			flag = 0; 
		}
		res.range = res.val[this->range+b.range-1]==0?this->range+b.range-1:this->range+b.range;
		return res;
	}
	
	BigN operator=(const BigN b){
		this->range = b.range;
		for(int i=0;i<b.range;i++)
			this->val[i] = b.val[i];
		return *this;
	}
	
	friend ostream &operator<<( ostream &output, const BigN &a ){ 
		output<<a.val[a.range-1];
		for(int i=a.range-2;i>=0;i--){
			if(a.val[i]==0) output<<"000";
			else if(a.val[i]<10)	output<<"00"<<a.val[i];
			else if(a.val[i]<100)	output<<"0"<<a.val[i];
			else output<<a.val[i];
		}
		return output;
	}
	
	
};

BigN dp[105];
int main(int argc, char *argv[]) {
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	BigN TWO(2);
	for(int i=3;i<=100;i++){
		dp[i] = dp[i-1]*TWO;
		for(int j=1;j<i-1;j++){
			dp[i] = dp[i] + dp[i-1-j]*dp[j];
		}
	}
	int n;
	while(scanf("%d", &n)!=EOF){
		cout<<dp[n]<<"\n";
	}
	return 0;
}