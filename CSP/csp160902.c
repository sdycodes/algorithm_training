#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	//freopen("./data.in", "r", stdin);
	int a[25][6];
	memset(a, 0, sizeof(a));
	int n;
	scanf("%d", &n);
	int number;
	for (int i = 0; i < n; i++) {
		scanf("%d", &number);
		int flag = 0;
		for (int r = 1; r <= 20; r++) {
			int cnt = 0;
			for (int c = 1; c <= 5; c++) {
				if (a[r][c] == 0) {
					cnt++;
				} else {
					cnt = 0;
				}
				if (cnt == number) {
					for (int k = 0; k < number; k++) {
						a[r][c - number + 1 + k] = 1;
						printf("%d ", (r - 1) * 5 + c - number + 1 + k);
					}
					printf("\n");
					flag = 1;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (flag) {
			continue;
		}
		int cnt = 0;
		flag = 0;
		for (int r = 1; r <= 20; r++) {
			for (int c = 1; c <= 5; c++) {
				if (a[r][c] == 0) {
					cnt++;
					a[r][c] = 1;
					printf("%d ", (r - 1) * 5 + c);
				}
				if (cnt == number) {
					flag = 1;
					printf("\n");
					break;
				}
			}
			if (flag) {
				break;
			}
		}
	}
	return 0;
}