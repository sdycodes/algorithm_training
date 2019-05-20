#include <iostream>
//看到数字比较小可以考虑模拟
//a，表示井的深度。
//b，表示柯南每小时爬的距离。 
//c，表示柯南每小时滑下的距离。
//d，表示隔多少米有凹槽。
#define max(a, b) (a > b? a:b)
using namespace std;
int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	while(N--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		//考虑fail情况
		if (b < a && b <= c && b < d) { 
				printf("fail\n");
				continue;	
		} 
		//模拟
		int cur = 0;
		int rnd = 0;
		while(cur < a) {
			rnd++;
			cur += b;
			if (cur >= a) break;
			int bot1 = cur - c;
			if (cur < d) {
				cur = bot1;
				continue;
			}
			int bot2 = cur - (cur % d);
			cur = max(bot1, bot2);
		}
		printf("%d\n", rnd);
	}
	return 0;
}