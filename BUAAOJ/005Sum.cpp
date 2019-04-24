#include <iostream>
#include <cstring>
//蛇皮题目
using namespace std;
char s[1000000000];
int main(int argc, char *argv[]) {
	long long sum = 0;
	scanf("%s", s);
	for (int i=0;i<strlen(s);i++) 
		sum += (s[i]-'0');
	while(sum > 9){
		long long rec = sum;
		sum = 0;
		while(rec){
			sum += (rec%10);
			rec /= 10;
		}
	}
	cout<<sum;
	return 0;
}