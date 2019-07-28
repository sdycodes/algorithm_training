#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    return a < b? a:b;
}

int max(int a, int b) {
    return a > b? a: b;
}

char s[105];
char t[105];

int main() {
    #ifdef L
        freopen("data.in", "r", stdin);
    #endif
    while(scanf("%s", s) != EOF) {
        scanf("%s", t);
        int slen = strlen(s);
        int tlen = strlen(t);
        int res = slen + tlen;
        for (int pos = 0; pos < tlen; pos++) {
            int can = 1;
            for (int i = 0; i < min(slen, tlen - pos); i++) {
                if (s[i] - '0' + t[i + pos] - '0'> 3) {
                    can = 0;
                    break;
                }
            }
            if (can) {
                res = min(res, slen + pos);
            }
        }

        for (int pos = 0; pos < slen; pos++) {
            int can = 1;
            for (int i = 0; i < min(tlen, slen - pos); i++) {
                if (t[i] - '0' + s[i + pos] - '0' > 3) {
                    can = 0;
                    break;
                }
            }
            if (can) {
                res = min(res, tlen + pos);
            }
        }
        if (res < max(tlen, slen)) {
            res = max(tlen, slen);
        }
        printf("%d\n", res);
    }
    return 0;
}