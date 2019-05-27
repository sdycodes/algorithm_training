#include <cstdio>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
	char s[10005];
	while(scanf("%s", s) != EOF) {
		int len = strlen(s);
		int n;
		if (len == 1) {
			n = s[0] - '0';
		} else{
			n = (s[strlen(s) - 2] - '0') * 10 + (s[strlen(s) - 1] - '0');
		}
		printf("%d\n", (n % 4 == 1 || n % 4 == 2)?1:0);
	}
	return 0;
}