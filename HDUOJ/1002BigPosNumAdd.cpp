#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class BigUint{
	public:
		int bits;
		int nums[130];
		BigUint(){
			bits = 0;
			memset(nums, 0, sizeof(nums));
		}
		void add(BigUint b, BigUint &res){
			int flag = 0;
			int i, bound = this->bits>=b.bits?this->bits:b.bits;
			for(i=0;i<bound;i++){
				res.nums[i] = (this->nums[i]+b.nums[i]+flag)%100000000;
				flag = (this->nums[i]+b.nums[i]+flag)/100000000;
			}
			res.nums[bound] = flag;
			res.bits = flag?bound+1:bound;
		}
		void output(){
			printf("%d", this->nums[bits-1]);
			for(int i=bits-2;i>=0;i--)
				printf("%08d", this->nums[i]);
		}	
		void reset(){
			this->bits = 0;
			memset(this->nums, 0, sizeof(nums));
		}
		void trans(string snum){
			int i, len;
			len = strlen(snum.c_str());
			this->bits = len/8 + (len%8?1:0);
			i= 0;
			while(i<this->bits){
				if(len-8*(i+1)>=0)
					this->nums[i] = atoi(snum.substr(len-8*(i+1), 8).c_str());
				else
					this->nums[i] = atoi(snum.substr(0, len-8*i).c_str());
				i++;
			}
		}
};
int main(int argc, char *argv[]) {
	int T, i;
	BigUint a, b, c;
	string snum;
	scanf("%d", &T);	
	for(i=0;i<T;i++){
		if(i!=0)	printf("\n");
		a.reset();
		b.reset();
		c.reset();
		
		
		snum.clear();
		snum.resize(1002);
		scanf("%s", &snum[0]);
		a.trans(snum);
		getchar();
		
		snum.clear();
		snum.resize(1002);
		scanf("%s", &snum[0]);
		b.trans(snum);
		getchar();
		
		a.add(b, c);
		printf("Case %d:\n", i+1);
		a.output();
		printf(" + ");
		b.output();
		printf(" = ");
		c.output();	
		printf("\n");
	}
}