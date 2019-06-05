#include <cstdio>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	char s[2000];
	while(scanf("%d", &n) != EOF) {
		getchar();
		scanf("%s", s);
		for (int i = 0; i < n; i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				printf("%c", s[i]);
			} else {
				printf("%d", s[i]);
			}
		}
		printf("\n");
	}
}