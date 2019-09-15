#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
long long c2n(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'a' + 10;
}

long long getnum(char s[], long long rad) {
    long long res = 0;
    for (int i = 0; i < strlen(s); i++) {
        res = res * rad + c2n(s[i]);
    }
    return res;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    char n1[20], n2[20];
    int tag, rad;
    scanf("%s%s%d%d", n1, n2, &tag, &rad);
    if (tag == 2) {
        for (int i = 0; i < 15; i++) {
            char t = n1[i];
            n1[i] = n2[i];
            n2[i] = t;
        }
    }
    long long a1 = getnum(n1, rad);
    
    long long rbase = -1;
    long long l = 2;
    for (int i = 0; i < strlen(n2); i++) {
        l = max(l, c2n(n2[i]) + 1);
    }
    long long r = max(a1, l);
    while(l <= r) {
        long long m = (l + r) >> 1;
        long long a2 = getnum(n2, m);
        if (a1 < a2 || a2 < 0) r = m - 1;
        else if (a1 == a2) {rbase = m; break; }
        else l = m + 1;
    }
    if (rbase == -1) printf("Impossible\n");
    else printf("%lld\n", rbase);
    return 0;
}