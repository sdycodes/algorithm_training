#include <stdio.h>
#include <string.h>

char s[200000];
char g[200000];
int show[26];

int judge(int kase, int wrong) {
    if (wrong > 6) {
        return 0;
    } 
    for (int i = 0; i < 26; i++) {
        if (show[i] > 0) {
            return 1;
        }
    }
    return 2;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int kase;
    while(scanf("%d", &kase) && kase != -1) {
        printf("Round %d\n", kase);
        scanf("%s", s);
        scanf("%s", g);
        memset(show, 0, sizeof(show));
        int slen = strlen(s);
        for (int i = 0; i < slen; i++) {
            show[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (show[i] == 0) {
                show[i] = -1;
            }
        }
        int glen = strlen(g);
        int wrong = 0;
        int res;
        for (int i = 0; i < glen; i++) {
            if (show[g[i] - 'a'] >= 0) {
                show[g[i] - 'a'] = 0;
            } else {
                wrong++;
            }
            res = judge(kase, wrong);
            if (res != 1) {
                break;
            }
        }
        if (res == 0) {
            printf("You lose.\n");
        } else if (res == 1) {
            printf("You chickened out.\n");
        } else {
            printf("You win.\n");
        }
    }
    return 0;
}