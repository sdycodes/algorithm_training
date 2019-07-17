#include <stdio.h>

int min(int a, int b) {
    return a < b? a : b;
}
int main() {
    //freopen("data.in","r",stdin);
    int n;
    int a[505][505];
    scanf("%d", &n);
    for (int i = 1; i <=n; i++) {
        for (int j = 1;j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= 2 * n - 1; i++) {
        int num = 0;
        if (i <= n) {
            num = i;
        } else {
            num = 2 * n - i;
        }
        int r, c;
        if (i % 2 == 0) {
            c = min(i, n);
            r = i + 1 - c;
        } else {
            r = min(i, n);
            c = i + 1 - r;
        }
        for (int j = 0; j < num; j++) {
            // r + c = i + 1
            // r = min(i, n)  odd
            // c = min(i, n)  even
            if (i % 2 == 0) {
                printf("%d ", a[r + j][c - j]);
            } else {
                printf("%d ", a[r - j][c + j]);
            }
        }
    }
    return 0;
}