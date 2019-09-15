#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int maxn = 1005;
const int maxm = 10005;
struct Edge{
    int u, v;
    Edge(int u=0, int v=0): u(u), v(v) {}
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

vector<Edge> edges2;
vector<int> Gr[maxn];
void G2_init() {
    edges2.clear();
    for (int i = 0; i < maxn; i++) {
        Gr[i].clear();
    }
}
void add_edge2(int u, int v) {
    edges2.push_back(Edge(u, v));
    Gr[u].push_back(edges2.size() - 1);
}

int vis[maxn];

int bfs(int src) {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    int res = 0;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        res++;
        for (int k = 0; k < G[u].size(); k++) {
            Edge& e = edges[G[u][k]];
            if (!vis[e.v]) {
                vis[e.v] = 1;
                q.push(e.v);   
            }
        }
    }
    return res;
}

int bfs2(int src) {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    int res = 0;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        res++;
        for (int k = 0; k < Gr[u].size(); k++) {
            Edge& e = edges2[Gr[u][k]];
            if (!vis[e.v]) {
                vis[e.v] = 1;
                q.push(e.v);
            }
        }
    }
    return res;
}

int rec[maxn];
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    G_init();
    G2_init();
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge2(v, u);
    }
    memset(rec, 0, sizeof(rec));
    for (int i = 1; i <= n; i++) {
        if (bfs(i) == n) rec[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (bfs2(i) == n) rec[i] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (rec[i]) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}