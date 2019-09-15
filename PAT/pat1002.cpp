#include <cstdio>
#include <cstring>

double poly1[1005];
double poly2[1005];
double sp[1005];

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int k, n;
    double a;
    memset(poly1, 0, sizeof(poly1));
    memset(poly2, 0, sizeof(poly2));
    memset(sp, 0, sizeof(sp));
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%lf", &n, &a);
        poly1[n] = a;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%lf", &n, &a);
        poly2[n] = a;
    }
    int cnt = 0;
    for (int i = 0; i < 1005; i++) {
        sp[i] = poly1[i] + poly2[i];
        if (sp[i] > 0.001 || sp[i] < -0.001) {
            cnt++;
        }
    }
    printf("%d", cnt);
    for (int i = 1004; i >= 0; i--) {
        if (sp[i] > 0.001 || sp[i] < -0.001) {
            printf(" %d %.1f", i, sp[i]);
        }
    }
    printf("\n");
    return 0;
}