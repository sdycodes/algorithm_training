#include <iostream>

using namespace std;
class BigN{
	public:
		int val[10000];
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
			res.val[i] = (this->val[i]+b.val[i]+flag)%10000;
			flag = (this->val[i]+b.val[i]+flag)/10000;
		}
		for(;i<big;i++){
			if(big==b.range){
				res.val[i] = (b.val[i]+flag)%10000;
				flag = (b.val[i]+flag)/10000;
			}
			else{
				res.val[i] = (this->val[i]+flag)%10000;
				flag = (this->val[i]+flag)/10000;
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
				res.val[i+j] = tmp%10000;
				flag = tmp/10000;
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
			if(a.val[i]==0) output<<"0000";
			else if(a.val[i]<10)	output<<"000"<<a.val[i];
			else if(a.val[i]<100)	output<<"00"<<a.val[i];
			else if(a.val[i]<1000)	output<<"0"<<a.val[i];
			else output<<a.val[i];
		}
		return output;
	}
	
	
};

int main(int argc, char *argv[]) {
	int N;
	while(scanf("%d", &N)!=EOF){
		BigN res = BigN(1);
		for(int i=2;i<=N;i++){
			BigN tmp = BigN(i);
			res = res*tmp;
		}
		cout<<res<<"\n";
	}
	return 0;
}