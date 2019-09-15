#include <cstdio>

int rch[1005], lch[1005];


int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n, k;
    scanf("%d%d", &n, &k);
    rch[n] = 1;
    lch[n] = n - 1;
    rch[1] = 2;
    lch[1] = n;
    for (int i = 2; i <= n - 1; i++) {
        rch[i] = i + 1;
        lch[i] = i - 1;
    }  
    int rem = n;
    int num = 0;
    int pos = n;
    while(rem != 1) {
        pos = rch[pos];
        ++num;
        if (num % k == 0 || num % 10 == k) {
            rem--;
            lch[rch[pos]] = lch[pos];
            rch[lch[pos]] = rch[pos];
            pos = lch[pos];
        }
    }
    printf("%d\n", rch[pos]);
    return 0;
}

