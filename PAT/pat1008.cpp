#include <cstdio>

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int N;
    scanf("%d", &N);
    int cur = 0;
    int res = 0;
    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        if (cur > t) {
            res += (cur - t) * 4;
        } else {
            res += (t - cur) * 6;
        }
        res += 5;
        cur = t;
    }
    printf("%d\n", res);
    return 0;
}