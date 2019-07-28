#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long res = 0;
    for (int i = 1; i <=n; i++) {
        res += ((n - i + 1) * (n - i + 1));
    }
    printf("%lld\n",res);
    return 0;
}