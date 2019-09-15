#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 305;

struct Node{
    int no, dis;
    Node(int no, int dis): no(no), dis(dis) {}
    bool operator<(const Node& b) const {
        return dis > b.dis;
    }
};
struct Edge{
    int u, v, a, b, t;
    Edge(int u = 0, int v = 0, int a = 0, int b = 0, int t = 0): u(u), v(v), a(a), b(b), t(t) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void G_init() {
    for (int i = 0; i < maxn; i++) G[i].clear();
    edges.clear();
    return;
}
void add_edge(int u, int v, int a, int b, int t) {
    edges.push_back(Edge(u, v, a, b, t));
    G[u].push_back(edges.size() - 1);
    return;
}

int dis[maxn], vis[maxn];

void dij(int src, int dst) {
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[src] = 0;
    priority_queue<Node> q;
    q.push(Node(src, 0));
    while(!q.empty()) {
        Node u = q.top(); q.pop();
        if (vis[u.no]) continue;
        vis[u.no] = 1;
        if (u.no == dst) break;
        for (int i = 0; i < G[u.no].size(); i++) {
            Edge& e = edges[G[u.no][i]];
            int arr;
            int T = e.a + e.b;
            if (u.dis % T > e.a) {
                // close
                arr = (u.dis / T + 1) * T + e.t;
            } else if ((u.dis + e.t) % T > e.a){
                // cannot out
                arr = ((u.dis + e.t) / T + 1) * T + e.t;
            } else {
                arr = u.dis + e.t;
            }
            if (dis[e.v] == -1 || dis[e.v] > arr) {
                dis[e.v] = arr;
                q.push(Node(e.v, arr));
            }
        }
    }
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int kase = 0;
    int n, m, src, dst;
    while(scanf("%d%d%d%d", &n, &m, &src, &dst) != EOF) {
        kase++;
        G_init();
        for (int i = 0; i < m; i++) {
            int u, v, a, b, t;
            scanf("%d%d%d%d%d", &u, &v, &a, &b, &t);
            if (a >= t) {
                add_edge(u, v, a, b, t);
            }
        }
        dij(src, dst);
        printf("Case %d: %d\n", kase, dis[dst]);
    }
    return 0;
}