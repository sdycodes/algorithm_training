#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
const int maxn = 105;
const double INF = 10000000000;
int x[maxn], y[maxn], z[maxn], r[maxn];
int n;
struct Node{
    int u;
    double d;
    Node(int u=0, double d=0): u(u), d(d) {}
    bool operator<(const Node& b) const {
        return d > b.d;
    }
};

double dist(int x0, int y0, int z0, int x1, int y1, int z1) {
    long long a = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1) + (z0 - z1) * (z0 - z1);
    return sqrt(a);
}
double dis[maxn];
int vis[maxn];
double g[maxn][maxn];
void dij() {
    for (int i = 0; i < maxn; i++) {
        dis[i] = -1.0;
    }
    memset(vis, 0, sizeof(vis));
    priority_queue<Node> q;
    q.push(Node(0, 0));
    dis[0] = 0;
    while(!q.empty()) {
        Node u = q.top(); q.pop();
        if (vis[u.u]) continue;
        vis[u.u] = 1;
        if (u.u == n + 1) break;
        for (int v = 0; v <= n + 1; v++) {
            if (dis[v] < -0.5 || dis[v] > dis[u.u] + g[u.u][v]) {
                dis[v] = dis[u.u] + g[u.u][v];
                q.push(Node(v, dis[v]));
            }
        }
    }
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    int kase = 0;
    while(scanf("%d", &n) != EOF) {
        if (n == -1) break;
        kase++;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d%d", &x[i], &y[i], &z[i], &r[i]);
        }
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < maxn; j++) {
                g[i][j] = INF;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j =i + 1; j <= n; j++) {
                double l = dist(x[i], y[i], z[i], x[j], y[j], z[j]);
                if (l - r[i] - r[j] > 0) {
                    g[j][i] = g[i][j] = l - r[i] - r[j];
                } else {
                    g[i][j] = g[j][i] = 0;
                }
            }
        }
        scanf("%d%d%d%d%d%d", &x[0], &y[0], &z[0], &x[n + 1], &y[n + 1], &z[n + 1]);
        for (int i = 1; i <= n; i++) {
            double l = dist(x[0], y[0], z[0], x[i], y[i], z[i]);
            if (l - r[i] > 0) g[0][i] = g[i][0] = l - r[i];
            else g[i][0] = g[0][i] = 0;
            l = dist(x[n+1], y[n+1], z[n+1], x[i], y[i], z[i]);
            if (l - r[i] > 0) g[n + 1][i] = g[i][n + 1] = l - r[i];
            else g[i][n + 1] = g[n + 1][i] = 0;
        }
        g[n+1][0] = g[0][n + 1] = dist(x[0], y[0], z[0], x[n+1], y[n+1], z[n+1]);
        dij();
        printf("Cheese %d: Travel time = %.0lf sec\n", kase, (10 * dis[n+1]));
    }
    return 0;
}