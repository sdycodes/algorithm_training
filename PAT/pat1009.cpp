#include <cstdio>
#include <cstring>

const int maxn = 1005;
long double res[2 * maxn];
double poly1[maxn];
double poly2[maxn];

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int k;
    memset(poly1, 0, sizeof(poly1));
    memset(poly2, 0, sizeof(poly2));
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int n;
        double c;
        scanf("%d%lf", &n, &c);
        poly1[n] = c;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int n;
        double c;
        scanf("%d%lf", &n, &c);
        poly2[n] = c;
    }
    memset(res, 0, sizeof(res));
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            res[i + j] += poly1[i] * poly2[j];
        }
    }
    int cnt = 0;
    for (int i = 2 * maxn - 1; i >= 0; i--) {
        if (res[i] > 0.001 || res[i] < -0.001) {
            cnt++;
        }
    }
    printf("%d", cnt);
    for (int i =2 * maxn - 1; i >= 0; i--) {
        if (res[i] > 0.001 || res[i] < -0.001) {
            printf(" %d %.1Lf", i, res[i]);
        }
    }
    printf("\n");
    return 0;
}