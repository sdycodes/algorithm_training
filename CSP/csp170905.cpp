#include <cstdio>

const int maxn = 100005;
int a[maxn];

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < M; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int l, r, v;
            scanf("%d%d%d", &l, &r, &v);
            for (int j = l; j <= r; j++) {
                if (a[j] % v == 0) a[j] /= v;
            }
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            int sum = 0;
            for (int j = l; j <= r; j++) {
                sum += a[j];
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}