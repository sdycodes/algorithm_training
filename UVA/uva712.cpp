#include <cstdio>
const int maxn = 10;
int n;
int order[maxn];
int children[1 << maxn];
int val[maxn];

void solve() {
    int l = 0, r = (1 << n) - 1;
    char s[50];
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        val[i] = s[i] - '0';
    }
    for (int i = 0; i < n; i++) {
        int t = val[order[i] - 1];
        int mid = (l + r) >> 1;
        if (t == 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (l != r) printf("error %d %d\n", l, r);
    printf("%d", children[l]);
}
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int kase = 0;
    while(1) {
        kase++;  
        scanf("%d", &n);
        if (n == 0) break;
        printf("S-Tree #%d:\n", kase);
        char s[250];
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            char t;
            sscanf(s, "%c%d", &t, &order[i]);
        }
        scanf("%s", s);
        for (int i = 0; i < (1 << n); i++) {
            children[i] = s[i] - '0';
        }
        int m;
        scanf("%d", &m);
        while(m--) {
            solve();
        }
        printf("\n\n");
    }
    return 0;
}