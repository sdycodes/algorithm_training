#include <iostream>

using namespace std;
int check[1005003];
//并不是线性筛  这道题是O(1)的
//因为每个数字的后继是唯一确定的 所以每次只看一个就能保证所有非self一定被去除
int main(int argc, char *argv[]) {
	memset(check, 0, sizeof(check));
	for(int i=1;i<=1000000;i++){
		int n = i;
		int sum = n;
		while(n){
			sum += n%10;
			n /= 10;
		}
		check[sum] = 1;
		if(!check[i])
			printf("%d\n", i);
	}
}