#include <iostream>
//注意前导0
using namespace std;
int main(int argc, char *argv[]) {
	int a, b, c, n;
	while(scanf("%d", &n)!=EOF){
		a = n%10;
		n /= 10;
		b = n%10;
		n/=10;
		c = n;
		printf("%d\n", a*100+b*10+c);
	}
	return 0;
}