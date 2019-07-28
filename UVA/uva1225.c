#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N;
        int cnt[10];
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            int tmp = i;
            while (tmp) {
                cnt[tmp % 10]++;
                tmp /= 10;
            }
        }
        for (int i = 0; i < 9; i++) {
            printf("%d ", cnt[i]);
        }
        printf("%d\n", cnt[9]);
    }
    return 0;
}