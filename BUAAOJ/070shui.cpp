#include <cstdio>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {
		getchar();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			char c;
			scanf("%c", &c);
			sum += (int)c;
		}
		printf("%d\n", sum);
	}
}