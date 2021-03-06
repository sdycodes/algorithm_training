#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int a[maxn];
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i <  n; i++) {
        scanf("%d", &a[i]);
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
        res = max(res, abs(a[i] - a[i - 1]));
    }
    printf("%d\n", res);
    return 0;
}