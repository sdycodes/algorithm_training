#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        char s[100];
        int cnt[4] = {0, 0, 0, 0};
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if (isalpha(s[i])) {
                int j = i + 1;
                int num = 0;
                while(j < len && isdigit(s[j])) {
                    num = num * 10 + s[j] - '0';
                    j++;
                }
                //printf("num: %d\n", num);
                if (num == 0) {
                    num = 1;
                }
                if (s[i] ==  'C') {
                    cnt[0] += num;
                } else if (s[i] == 'H') {
                    cnt[1] += num;
                } else if (s[i] == 'O') {
                    cnt[2] += num;
                } else {
                    cnt[3] += num;
                }
                //printf("%d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3]);
                //printf("i: %d\n", j);
                i = j - 1;
            }
        }
        double res = cnt[0] * 12.01 + cnt[1] * 1.008 + cnt[2] * 16.00 + cnt[3] * 14.01;
        printf("%.3f\n", res);
    }
    return 0;
}