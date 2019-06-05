#include <stdio.h>
#include <string.h>
int digSum(int a) {
	int res = 0;
	while (a) {
		res += a % 10;
		a /= 10;
	}
	return res;
}
int main(int argc, char *argv[]) {
	int tab[100005];
	int reTab[100005];
	memset(reTab, -1, sizeof(reTab));
	for (int i = 1; i < 100002; i++) {
		tab[i] = i + digSum(i);
		if (reTab[tab[i]] == -1) {
			reTab[tab[i]] = i;
		}
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		if (reTab[n] != -1) {
			printf("%d\n", reTab[n]);
		} else {
			printf("0\n");
		}
	}
	return 0;
}