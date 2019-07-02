#include <stdio.h>

int main(int argc, char *argv[]) {
	int N;
	scanf("%d", &N);
	int a[1005];
	for (int i = 1; i <= N; i++) {
		a[i] = i;
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int no, delta;
		scanf("%d%d", &no, &delta);
		int idx = 1;
		while(idx <= N && a[idx] != no) {
			idx++;
		}
		int r = a[idx];
		if (delta > 0) {
			for (int j = idx; j < idx + delta; j++) {
				a[j] = a[j + 1];
			}
			a[idx + delta] = r; 
		} else {
			delta *= -1;
			for (int j = idx; j > idx - delta; j--) {
				a[j] = a[j - 1];
			}
			a[idx - delta] = r;
		}
	}
	for (int i = 1; i <= N; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}