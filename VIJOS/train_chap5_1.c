#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define reopen do{if(DEBUG) freopen("data.in", "r", stdin);}while(0)

int a[200005];
int b[200005];
int n;

int place(int pos, long long d) {
    int l = ((pos - d) % (2 * n) + 2 * n) % (2 * n);
    int r = (pos + d) % (2 * n);
    if (l == 0) {
        l = 2 * n;
    } 
    if (r == 0) {
        r = 2 * n;
    }
    if (a[l] == 0) {
        return 0;
    }
    if (a[l] == a[r]) {
        return 1;
    }
    return 2;
}

int main() {
    reopen;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    long long T;
    scanf("%d%lld", &n, &T);
    for (int i = 1; i <= 2 * n; i += 2) {
        scanf("%d", &a[i]);
    }
    long long d = 1;
    while(T) {
        if (T & 1) {
            for (int i = 1; i <= 2 * n; i++) {
                b[i] = place(i, d);
            }
            for (int i = 1; i <= 2 * n; i++) {
                a[i] = b[i];
            }
        }
        T >>= 1;
        d <<= 1;
    }
    for (int i = 1; i <= 2 * n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}