#include <cstdio>
#include <cstring>

const int maxn = 1005;
int a[maxn];
int res[maxn];
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; i++) {
        int more = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] > a[j]) more++;
            else if (a[i] < a[j]) more--;
        }
        if (more == 0) res[a[i]] = 1;
    }
    int ok = 0;
    for (int i = 0; i <= 1000; i++) {
        if (res[i]) {
            printf("%d\n", i);
            ok = 1;
        }
    }
    if (!ok) printf("-1\n");
    
    return 0;
}