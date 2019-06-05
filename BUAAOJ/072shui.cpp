#include <cstdio>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	char s[205];
	while(scanf("%d", &n) != EOF) {
		getchar();
		scanf("%s", s);
		int i;
		for (i = 0; i < n - 2; i++) {
			if (s[i + 2] - s[i + 1] == 1 && s[i + 1] - s[i] == 1) {
				break;
			}
		}
		if (i == n-2){
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
}