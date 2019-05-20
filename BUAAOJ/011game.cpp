#include<cstdio>
using namespace std;
int main() {
	int a, b;
	// 本质是辗转相除过程的记录
	while (scanf("%d %d", &a, &b) != EOF) {
		bool firstWin = true;
		if (a > b) {
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
		}
		int r = 1;
		while (r) {
			if (b % a == 0 || b > 2 * a) {  //how to prove?
				break;
			}
			firstWin = !firstWin;
			r = b % a;
			b = a;
			a = r;
		}
		if (firstWin) {
			printf("Nova\n");
		} else {
			printf("LaoWang\n");
		}
	}
	return 0;
}