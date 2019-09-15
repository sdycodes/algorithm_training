#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10005;
int a[maxn];

long long maxsubarr(int l, int r, int& rl, int& rr) {
    if (r - l == 1) {
        rl = l;
        rr = l;
        return a[l];
    }
    int m = l + (r - l) / 2;
    long long cand1;
    int rl1, rr1, rl2, rr2, tl1, tr1;
    long long L = maxsubarr(l, m, rl1, rr1);
    long long R = maxsubarr(m, r, rl2, rr2);
    if (L >= R) {
        cand1 = L;
        tl1 = rl1;
        tr1 = rr1;
    } else {
        cand1 = R;
        tl1 = rl2;
        tr1 = rr2;
    }
    long long v, lsum, rsum;
    v = 0;
    lsum = a[m - 1];
    int tl2 = m - 1, tr2 = m;
    for (int i = m - 1; i >= l; i--) {
        v += a[i];
        if (lsum <= v) {
            lsum = v;
            tl2 = i;
        }
    }
    v = 0;
    rsum = a[m];
    for (int i = m; i < r; i++) {
        v += a[i];
        if (rsum < v) {
            rsum = v;
            tr2 = i;
        }
    }
    long long cand2 = lsum + rsum;
    if (cand1 > cand2) {
        rl = tl1;
        rr = tr1;
        return cand1;
    } else if (cand1 < cand2) {
        rl = tl2;
        rr = tr2;
        return cand2;
    } else {
        if (tl1 < tl2) {
            rl = tl1;
            rr = tr1;
        } else {
            rl = tl2;
            rr = tr2;
        }
        return cand1;
    }
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int rl, rr;
    long long res = maxsubarr(0, n, rl, rr);
    if (res < 0) printf("0 %d %d\n", a[0], a[n-1]);
    else printf("%lld %d %d\n", res, a[rl], a[rr]);
    return 0;
}