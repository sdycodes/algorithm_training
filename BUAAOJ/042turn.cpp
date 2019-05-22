#include <cstdio>
#define max(a, b) (a>b?a:b)
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {
		int a, b, res = -10000000;
		scanf("%d", &a);
		for(int i = 1; i < n; i++) {
			scanf("%d", &b);
			res = max(res, a - b);
			if(a - b < 0) {
				a = b;
			}
		}
		printf("%d\n", res);
	}
}