#include <cstdio>

int r, y, g;
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    scanf("%d%d%d", &r, &y, &g);
    int m;
    scanf("%d", &m);
    int res = 0;
    while(m--) {
        int k, t;
        scanf("%d%d", &k, &t);
        if (k == 0) {
            res += t;
        } else if (k == 1) {
            res += t;
        } else if (k == 2) {
            res += (t + r);
        }
    }
    printf("%d\n", res);
    return 0;
}