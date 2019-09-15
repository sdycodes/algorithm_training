#include <cstdio>
const int maxn = 1005;
int a[maxn];
int b[maxn];
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n - 1; i++) {
        b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;
    }
    b[0] = (a[0] + a[1]) / 2;
    b[n - 1] = (a[n - 1] + a[n - 2]) / 2;
    for (int i = 0; i < n - 1;  i++) {
        printf("%d ", b[i]);
    }
    printf("%d\n", b[n - 1]);
    return 0;
}