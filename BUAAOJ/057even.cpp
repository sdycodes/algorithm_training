#include <cstdio>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {
		if (n <= 3) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}