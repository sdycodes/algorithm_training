#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 1005;
double x[maxn], y[maxn], r[maxn];
int n;
int vis[maxn];
const double W = 1000.0;
double left;
double right;

double min(double a, double b) {
    return a < b ? a : b;
}

int intersect(int u, int v) {
    return sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v])) < r[u] + r[v];
}

void update(int u) {
    if (x[u] - r[u] < 0) {
        left = min(left, y[u] - sqrt(r[u] * r[u] - x[u] * x[u]));
    }
    if (x[u] + r[u] > W) {
        right = min(right, y[u] - sqrt(r[u] * r[u] - (W - x[u]) * (W - x[u])));
    }
}

int dfs(int u) {
    if (vis[u]) return false;
    vis[u] = 1;
    if (y[u] - r[u] < 0) return true;
    for (int i = 0; i < n; i++) {
        if (i != u && intersect(i, u) && dfs(i)) {
            return true;
        }
    }
    update(u);
    return false;
}

int main() {
    # ifdef D
        freopen("data.in", "r", stdin);
    #endif
    while(scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
        }
        memset(vis, 0, sizeof(vis));
        left = right = W;
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (y[i] + r[i] > W && dfs(i)) {
                ok = 0;
            }
        }
        if (ok) printf("0.00 %.2lf 1000.00 %.2lf\n", left, right);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}