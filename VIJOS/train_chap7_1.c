#include <stdio.h>
#define DEBUG 0
#define reopen do{if(DEBUG) freopen("data.in", "r", stdin);}while(0)

int gcd(int a, int b) {
    if (a > b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    int r = 1;
    while(r) {
        r = b % a;
        b = a;
        a = r;
    }
    return b;
}
int main() {
    reopen;
    int x, y;
    scanf("%d%d", &x, &y);
    if (y % x != 0) {
        printf("0\n");
        return 0;
    }
    int k = y / x;
    int ans = 0;
    for (int i = 1; i <= k; i ++) {
        if (k % i == 0 && gcd(i, k / i) == 1) {
            //printf("%d %d\n", i * x, k / i * x);
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}