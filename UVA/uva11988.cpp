#include <cstring>
#include <cstdio>

using namespace std;

char s[100005];
int next[100005];

int main() {
    #ifdef D
        printf("debug mode:\n");
        freopen("data.in", "r", stdin);
    #endif
    while(scanf("%s", s + 1) != EOF) {
        int cur = 0, last = 0;
        int n = strlen(s + 1);
        next[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '[') {
                cur = 0;
            } else if (s[i] == ']') {
                cur = last;
            } else {
                next[i] = next[cur];
                next[cur] = i;
                if (cur == last) {
                    last = i;
                }
                cur = i;
            }
        }
        for (int i = next[0]; i != 0; i = next[i]) {
            putchar(s[i]);
        }
        putchar('\n');
    }
    return 0;
}