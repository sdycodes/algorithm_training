#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
const int maxn = 10005;

struct Edge{
    int u, v, w;
    Edge(int u=0, int v=0,int w=0):u(u), v(v), w(w) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void G_init() {
    edges.clear();
    for (int i = 0; i < maxn; i++) {
        G[i].clear();
    }
}
void add_edge(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    G[u].push_back(edges.size() - 1);
}

struct Node{
    int n, d;
    Node(int n=0, int d=0):n(n), d(d) {}
    bool operator<(const Node& b) const {
        return d > b.d;
    }
};

int dis[maxn], vis[maxn], pre[maxn];
void dij(int src) {
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    priority_queue<Node> q;
    q.push(Node(src, 0));
    dis[src] = 0;
    while(!q.empty()) {
        Node u = q.top(); q.pop();
        if (vis[u.n]) continue;
        vis[u.n] = 1;
        for (int k = 0; k < G[u.n].size(); k++) {
            Edge& e = edges[G[u.n][k]];
            if (dis[e.v] == -1 || dis[e.v] > dis[u.n] + e.w) {
                dis[e.v] = dis[u.n] + e.w;
                q.push(Node(e.v, dis[e.v]));
                pre[e.v] = G[u.n][k];
            } else if (dis[e.v] == dis[u.n] + e.w) {
                pre[e.v] = e.w > edges[pre[e.v]].w?pre[e.v]: G[u.n][k];
            }
        }
    }
    return;
}

int bfs() {
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    int res = 0;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int k = 0; k < G[u].size(); k++) {
            Edge& e = edges[G[u][k]];
            if (!vis[e.v] && pre[e.v] == G[u][k]) {
                q.push(e.v);
                vis[e.v] = 1;
                res += e.w;
            }
        }
    }
    return res;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif 
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dij(1);
    int res = bfs();
    printf("%d\n", res);
    return 0;
}