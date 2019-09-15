#include <cstdio>

const int maxn = 1005;
int a[maxn];

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) {
        a[i] = i;
    }
    while(m--) {
        int p, s;
        scanf("%d%d", &p, &s);
        int pos = 1;
        while(a[pos] !=  p) pos++;
        if (s > 0) {
            for (int i = pos; i < pos + s; i++) {
                a[i] = a[i + 1];
            }
            a[pos + s] = p;
        } else {
            s = -s;
            for (int i = pos; i > pos  - s; i--) {
                a[i] = a[i - 1];
            }
            a[pos - s] = p;
        }
    }
    for (int i = 1; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n]);
    return 0;
}