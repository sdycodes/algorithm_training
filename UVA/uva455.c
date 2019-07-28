#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    char buf[100];
    while(N--) {
        fgets(buf, 100, stdin);
        char s[100];
        scanf("%s", s);
        int lens = strlen(s);
        int len;
        for (len = 1; len < lens; len++) {
            if (lens % len != 0) {
                continue;
            }
            int flag = 1;
            for (int pos = 0; pos < len; pos++) {
                char tar = s[pos];
                for (int start = len; start < lens; start += len) {
                    if (tar != s[start + pos]) {
                        flag = 0;
                    }
                }
                if (flag == 0) {
                    break;
                }
            }
            if (flag == 0) {
                continue;
            } else {
                break;
            }
        }
        printf("%d\n", len);
        if (N) {
            printf("\n");
        }
    }
    return 0;
}