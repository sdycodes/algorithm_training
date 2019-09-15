#include <cstdio>


int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n, k;
    scanf("%d%d", &n, &k);
    int cnt = 0;
    int cur = 0;
    while(n--) {
        int t;
        scanf("%d", &t);
        cur += t;
        if (cur >= k) {
            cur = 0;
            cnt++;
        }
    }
    if (cur > 0) cnt++;
    printf("%d\n", cnt);
    return 0;
}