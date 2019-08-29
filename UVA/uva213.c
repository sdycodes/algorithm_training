#include <stdio.h>

char s[1000000];


void parse() {
    int state = 0, len = 0, dig = 0, ord = 0;
    while(1) {
        char c = getchar();
        if (c != '0' && c != '1') {
            continue;
        }
        if (state == 0) {
            len = len * 2 + c - '0';
            dig++;
            if (dig == 3) {
                dig = 0;
                state = 1;
                if (len == 0) {
                    break;
                }
            }
        } else {
            ord = ord * 2 + c - '0';
            dig++;
            if (dig == len) {
                if (ord == (1 << len) - 1) {
                    state = 0;
                    len = 0;
                    ord = 0;
                    dig = 0;
                    continue;
                }
                printf("%c", s[(1 << len) - len - 1 + ord]);
                ord = 0;
                dig = 0;
            }
        }
    }
    char c;
    do {
        c = getchar();
    } while(c != '\n');
    return;
}

int main() {
    #ifdef D
        printf("debug mode\n");
        freopen("data.in", "r", stdin);
    #endif
    while(fgets(s, 1005, stdin)) {
        parse();
        printf("\n");
    }
    return 0;
}