#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEBUG 0

#define reopen do{if (DEBUG) freopen("data.in", "r", stdin);}while(0)
#define showvar(...) do{ if(DEBUG){ \
                            printf("DEBUG:"); \
                            printf(__VA_ARGS__); \
                            printf("\n");} \
                        }while(0)


int isParli(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int c2n(char a) {
    return (a >= '0' && a <= '9')? (a - '0'): (a - 'A' + 10);
}

int n2c(int n) {
    return (n >= 0 && n <= 9)? ((char)(n + '0')):((char)(n - 10 + 'A'));
}

char* add(char s[], int base) {
    char *t = (char *)malloc(sizeof(char) * 10000);
    strcpy(t, s);
    int len = strlen(s);
    int next = 0, cur = 0;
    for (int i = 0; i < len; i++) {
        cur = c2n(t[i]) + c2n(s[len - i - 1]) + next;
        next = cur / base;
        t[i] = n2c(cur % base);
    }
    if (next != 0) {
        t[len] = n2c(next);
    }
    return t;
}

int main() {
    reopen;
    int base;
    scanf("%d", &base);
    char s[10000];
    scanf("%s", s);
    int len = (int)strlen(s);
    int step = 0;
    char * t = s;
    while(step <= 30 && !isParli(t)) {
        step++;
        t = add(t, base);
        showvar("t: %s", t);
    }
    if (isParli(t)) {
        printf("STEP=%d\n", step);
    } else {
        printf("Impossible!\n");
    }
    return 0;
}

