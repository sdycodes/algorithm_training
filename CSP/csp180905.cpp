#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxm = 1005;
const int Q = 998244353;
long long k[maxm];
long long a[200005];
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int m, l, r;
    scanf("%d%d%d", &m, &l, &r);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &k[i]);
    }
    memset(a, 0, sizeof(a));
    a[0] = 1;
    for (int n = 1; n <= r; n++) {
        for (int i = 1; i <= min(n, m); i++) {
            a[n] += (k[i] * a[n - i]) % Q;
            a[n] %= Q;
        }
    }
    for (int i = l; i <= r; i++) {
        printf("%lld\n", a[i]);
    }
    return 0;
}