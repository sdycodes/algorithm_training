#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[]) {
	int tmp;
	int res = 0;
	int cur = 1;
	while(scanf("%d", &tmp)){
		if(tmp==0)
			break;
		if(tmp==1){
			res +=1;
			cur = 1;
		}
		else{
			if(cur==1){
				res += 2;
				cur = 2;
			}
			else{
				cur += 2;
				res += cur;
			}
		}
	}
	cout<<res;
	return 0;
}