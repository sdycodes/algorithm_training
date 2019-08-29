#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 105;
const int INF = 1000000000;
int N, M, Q;
int d[maxn][maxn];

void floyed() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
                }
            }
        }
    }
    return;
}
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int kase = 0;
    while(scanf("%d%d%d", &N, &M, &Q)) {
        kase++;
        if (N == 0 && M == 0 && Q == 0) break;
        if (kase != 1) printf("\n");
        for (int i = 1; i <= N;i++) {
            d[i][i] = 0;
            for(int j = i + 1; j <= N; j++) {
                d[i][j] = d[j][i] = INF;
            }
        }
        for (int i = 0; i < M; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            d[u][v] = min(d[u][v], w);
            d[v][u] = d[u][v];
        }
        floyed();
        printf("Case #%d\n", kase);
        for (int i = 0; i < Q; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (d[u][v] != INF) printf("%d\n", d[u][v]);
            else printf("no path\n");
        }
    }
    return 0;
}

