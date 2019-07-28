#include <stdio.h>

int main() {
    int rec[105];
    int a, b, c;
    int kase = 0;
    while (scanf("%d%d%d", &a, &b, &c) ==3 && !(a == 0 && b == 0 && c == 0)) {
        kase++;
        int cnt = 0;
        while(cnt < c + 2) {
            rec[cnt++] = a / b;
            a = (a % b) * 10;
        }
        cnt--;
        if (rec[cnt] >= 5) {
            rec[--cnt]++;
            while(cnt >= 1 && rec[cnt] == 10) {
                rec[cnt] = 0;
                rec[--cnt]++;
            }
        }
        printf("Case %d: ", kase);
        for (int i = 0; i < c + 1; i++) {
            printf("%d", rec[i]);
            if (i == 0 && i != c) {
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}