#include <stdio.h>
int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int mi = 5000;
		int secmi = 5000;
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp <= mi) {
				secmi = mi;
				mi = tmp;
			} else if (tmp < secmi) {
				secmi = tmp;
			} 
		}
		printf("%d\n", secmi);
	}
	return 0;
}