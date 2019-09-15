#include <cstdio>
const int maxn = 1005;
int a[maxn];

int main(){
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}