#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 505;
const int maxm = 100005;

struct Edge{
    int u, v, r, w;
    Edge(int u=0, int v=0, int r=0, int w=0): u(u), v(v), r(r), w(w) {}
};

struct Node{
    int u;
    long long dis, pre;
    Node(int u, long long dis, long long pre): u(u), dis(dis), pre(pre) {}
    bool operator<(const Node& b) const {
        return dis > b.dis;
    }
};

vector<int> G[maxn];
vector<Edge> edges;
void add_edge(int u, int v, int r, int w) {
    edges.push_back(Edge(u, v, r, w));
    G[u].push_back(edges.size() - 1);
}
void G_init() {
    edges.clear();
    for (int i = 0; i < maxn; i++) G[i].clear();
}
int n, m;

int vis[maxn];
long long dis[maxn];
void dij(int src) {
    memset(vis, 0, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    priority_queue<Node> q;
    q.push(Node(src, 0, 0));
    dis[src] = 0;
    while(!q.empty()) {
        Node u = q.top(); q.pop();
        if (vis[u.u]) continue;
        vis[u.u] = 1;
        for (int k = 0; k < G[u.u].size(); k++) {
            Edge& e = edges[G[u.u][k]];
            if (e.r == 0) {
                if (dis[e.v] == -1 || dis[e.v] > dis[u.u] + e.w) {
                    dis[e.v] = dis[u.u] + e.w;
                    q.push(Node(e.v, dis[e.v], 0));
                }
            } else {
                if (dis[e.v] == -1 || dis[e.v] > dis[u.u] - u.pre * u.pre + (e.w + u.pre) * (u.pre + e.w)) {
                    dis[e.v] = dis[u.u] - u.pre * u.pre + (e.w + u.pre) * (u.pre + e.w);
                    q.push(Node(e.v, dis[e.v], u.pre + e.w));
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
    scanf("%d%d", &n, &m);
    G_init();
    for (int i = 0; i < m; i++) {
        int r, u, v, w;
        scanf("%d%d%d%d", &r, &u, &v, &w);
        add_edge(u, v, r, w);
        add_edge(v, u, r, w);
    }
    dij(1);
    printf("%lld\n", dis[n]);
    return 0;
}