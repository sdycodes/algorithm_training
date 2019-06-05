#include <cstdio>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
	char s[1000];
	while(scanf("%s", s) != EOF) {
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] >= 'a' && s[i] <='z') {
				s[i] = s[i] - 'a' + 'A';
			} else if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = s[i] - 'A' + 'a';
			}
		}
		printf("%s\n", s);
		s[0] = '\0';
	}
}