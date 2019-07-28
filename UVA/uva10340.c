#include <stdio.h>
#include <string.h>

char s[1000005], t[1000005];

int main() {
    #ifdef DEBUG
        freopen("data.in", "r", stdin);
    #endif
    while(scanf("%s%s", s, t) != EOF) {
        int slen = strlen(s);
        int tlen = strlen(t);
        int pos = 0;
        for (int i = 0; i < tlen; i++) {
            if (s[pos] == t[i]) {
                pos++;
                if (pos == slen) {
                    break;
                }
            }
        }
        if (pos == slen) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}