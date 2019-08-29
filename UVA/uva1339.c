#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000000];

int comp(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    while(scanf("%s", s) != EOF) {

        int cnt1[26];
        memset(cnt1, 0, sizeof(cnt1));
        for (int i = 0; i < strlen(s); i++) {
            cnt1[s[i] - 'A']++;
        }
        scanf("%s", s);
        int cnt2[26];
        memset(cnt2, 0, sizeof(cnt2));
        for (int i = 0; i < strlen(s); i++) {
            cnt2[s[i] - 'A']++;
        }
        qsort(cnt1, 26, sizeof(int), comp);
        qsort(cnt2, 26, sizeof(int), comp);
        int flag = 1;
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}