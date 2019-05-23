#include <cstdio>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			if (i <= n/2) {
				for (int j = 0; j < n / 2 - i; j++) {
					printf(" ");
				}
				for (int j = 0; j < i + 1; j++) {
					printf("%c", 'A' + j);
				}
				for (int j = i - 1; j >= 0; j--) {
					printf("%c", 'A' + j);
				}
			} else {
				for (int j = 0; j < i - n / 2; j++) {
					printf(" ");
				}
				for (int j = 0; j < n - i ; j++) {
					printf("%c", 'A' + j);
				}
				for (int j = n - i - 2; j >=0; j--) {
					printf("%c", 'A' + j);
				}
			}
			printf("\n");
		}
	}
	return 0;
}