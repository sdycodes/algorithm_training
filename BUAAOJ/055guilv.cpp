#include <cstdio>
using namespace std;
int main(int argc, char *argv[]) {
	long long tab[21];
	tab[1] = 0;
	tab[2] = 1;
	for (int i = 3; i <= 20; i++) {
		tab[i] = (i - 1)*(tab[i-1]+tab[i-2]);
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%lld\n", tab[n]);
	}
	return 0;
}
