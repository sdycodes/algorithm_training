#include <cstdio>

using namespace std;
int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		printf("%d %d\n", n/m, (n/m)*m);
	}
}
