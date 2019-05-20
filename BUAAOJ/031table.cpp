#include <iostream>
#define min(a, b) (a < b?a:b)
using namespace std;
int main(int argc, char *argv[]) {
	int n, x;
	while(scanf("%d%d", &n, &x)!=EOF) {
		int cnt = 0;
		for (int i = 1; i <= min(n, x); i++) {
			if (x % i == 0 && x / i <= n) {
				cnt ++;
			}
		}
		printf("%d\n", cnt);
	}
}