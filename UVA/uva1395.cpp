#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 105;
const int maxm = 5 * maxn * maxn;

int n, m, L, R;
struct Edge{
    int u, v, w;
    Edge(int u=0, int v=0, int w=0):u(u), v(v), w(w) {}
    bool operator < (const Edge & e) const {
        return w < e.w;
    }
} edges[maxm];

//union set
int p[maxn];
void init_us(int n) { for (int i = 0; i < n; i++) p[i] = i; }
int find(int x) {return x == p[x]? x : p[x] = find(p[x]); }
void cup(int rep1, int rep2) {p[rep1] = rep2; }

void kruskal() {
    init_us(n + 1);
    int cnt = 0;
    for (R = L; R < m; R++) {
        int u = edges[R].u, v = edges[R].v;
        int repu = find(u), repv = find(v);
        if (repu != repv) {
            cup(repu, repv);
            cnt++;
            if (cnt == n - 1) break;
        }
    }
}

int main() {
    #ifdef D
    freopen("data.in", "r", stdin);
    #endif
    while(scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edges[i].u = u;
            edges[i].v = v;
            edges[i].w = w;
        }
        sort(edges, edges + m);
        int ans = -1;
        for (L = 0; L < m; L++) {
            kruskal();
            if (R != m) {
                if (ans == -1) ans = edges[R].w - edges[L].w;
                else ans = min(ans, edges[R].w - edges[L].w);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}