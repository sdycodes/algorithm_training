#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
//能不能找到所有和互质是等价的

//最大公因数 辗转相除法
//最小公倍数 两数之积/最大公因数
int gcd(int n, int m){
	int c;
	c = n%m;
	while(c){
		n = m;
		m = c;
		c = n%m;
	}
	return m;
}
int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &n, &m)&&!(m==-1&&n==-1)){
		if(gcd(n, m)==1)	printf("YES\n");
		else printf("POOR Haha\n");
	}
}