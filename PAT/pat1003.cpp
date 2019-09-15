#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 505;

struct Edge{
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w) {}
};
vector<Edge> edges;
vector<int> G[maxn];
int values[maxn];
struct Node{
    int n, d;
    Node(int n=0, int d = 0): n(n), d(d) {}
    bool operator<(const Node& b) const {
        return d > b.d;
    }
};
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
int dis[maxn], vis[maxn], hands[maxn];
long long pre_num[maxn];
void dij(int src, int dst) {
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(pre_num, 0, sizeof(pre_num));
    memset(hands, 0, sizeof(hands));
    priority_queue<Node> q;
    dis[src] = 0;
    hands[src] = values[src];
    pre_num[src] = 1;
    q.push(Node(src, dis[src]));
    while(!q.empty()) {
        Node u = q.top(); q.pop();
        if (vis[u.n]) continue;
        vis[u.n] = 1;
        if (u.n == dst) break;
        for (int i = 0; i < G[u.n].size(); i++) {
            Edge e = edges[G[u.n][i]];
            if (dis[e.v] == -1 || dis[e.v] > dis[u.n] + e.w) {
                pre_num[e.v] = pre_num[u.n];
                dis[e.v] = dis[u.n] + e.w;
                q.push(Node(e.v, dis[e.v]));
                hands[e.v] = hands[u.n] + values[e.v];
            } else if (dis[e.v] == dis[u.n] + e.w) {
                pre_num[e.v] += pre_num[u.n];
                hands[e.v] = max(hands[e.v], hands[u.n] + values[e.v]);
            }
        }
    }
    return;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int N, M, src, dst;
    scanf("%d%d%d%d", &N, &M, &src, &dst);
    for (int i = 0; i < N; i++) {
        scanf("%d", &values[i]);
        hands[i] = values[i];
    }
    G_init();
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dij(src, dst);
    printf("%lld %d\n", pre_num[dst], hands[dst]);
    return 0;
}