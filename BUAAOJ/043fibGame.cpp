#include <iostream>
#define END 46
using namespace std;
int fib[END];
//fib第46个值 开始溢出
int main(int argc, char *argv[]) {
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < END; i++) {
		fib[i] = fib[i - 1] + fib[i-2];
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		int i;
		for (i = 0; i < END; i++) {
			if (fib[i] == n) {
				break;
			}
		}
		if (i == END) {
			printf("Oh,yes!\n");
		} else {
			printf("Oh,holly shit!\n");
		}
	}
	return 0;
}