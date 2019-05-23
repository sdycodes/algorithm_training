#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000005];
bool comp(const int &a, const int &b) {
	return a > b;
}
int main(int argc, char *argv[]) {
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n, comp);
		printf("%d\n", a[k - 1]);
	}
	return 0;
}