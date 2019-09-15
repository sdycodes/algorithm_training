#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 20005;

struct Edge{
    int u, v;
    Edge(int u=0, int v=0):u(u), v(v) {}
};

vector<Edge> edges;
vector<int> G[maxn];
void G_init() {
    edges.clear();
    for (int i = 0; i < maxn; i++) {
        G[i].clear();
    }
}
void add_edge(int u, int v) {
    edges.push_back(Edge(u, v));
    G[u].push_back(edges.size() - 1);
}
int dis[maxn];
void bfs(int src) {
    memset(dis, -1, sizeof(dis));
    dis[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int k = 0; k < G[u].size(); k++) {
            Edge& e = edges[G[u][k]];
            if (dis[e.v] == -1) {
                dis[e.v] = dis[u] + 1;
                q.push(e.v);
            }
        }
    }
}

int main() {
    #ifdef D   
        freopen("data.in", "r", stdin);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; i++) {
        int u;
        scanf("%d", &u);
        add_edge(u, i);
        add_edge(i, u);
    }
    for (int i = 1; i <= m; i++) {
        int u;
        scanf("%d", &u);
        add_edge(u, i + n);
        add_edge(i + n, u);
    }
    bfs(1);
    int maxl = 0;
    int rec = -1;
    for (int i = 1; i <= n + m; i++) {
        if (maxl < dis[i]) {
            rec = i;
            maxl = dis[i];
        }
    }
    bfs(rec);
    for (int i = 1; i <= n + m; i++) {
        maxl = max(maxl, dis[i]);
    }
    printf("%d\n", maxl);
    return 0;
}