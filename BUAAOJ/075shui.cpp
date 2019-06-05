#include <cstdio>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	char s[2000];
	while(scanf("%d", &n) != EOF) {
		getchar();
		scanf("%s", s);
		int i = 1;
		for (i = 1; i < strlen(s) - 1; i++) {
			if (s[i] >='A' && s[i] <= 'Z' && s[i-1] >='a' && s[i-1]<='z'&&s[i+1]>='a'&&s[i-1]<='z') {
				break;	
			}
		}
		if (i >= strlen(s) - 1) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
}