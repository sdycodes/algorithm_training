#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define reopen do{if(DEBUG) freopen("data.in", "r", stdin);}while(0)
#define showvar(...) do{if(DEBUG) printf(__VA_ARGS__);}while(0)
#define MOD 1234567

long long pre[500005];
long long ticket[100000];

long long comb(int n, int r) {
    if (r < n - r) {
        r = n - r;
    }
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (i + (n - r)) / i;
    }
    return res;
}
int main() {
    reopen;
    int n, k;
    memset(ticket, 0, sizeof(ticket));
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &pre[i]);
        if (i >= 1) {
            pre[i] = pre[i] + pre[i - 1];
        }
        pre[i] %= k;
        ticket[pre[i]]++;
    }
    long long res = 0;
    for (int i = 0; i <= k; i++) {
        res = (res + comb(ticket[i], 2)) % MOD;
    }
    res = (res + ticket[0]) % MOD;
    printf("%lld\n", res);
    return 0;
}