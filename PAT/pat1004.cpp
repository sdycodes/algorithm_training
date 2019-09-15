#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int maxn = 105;
struct Node{
    int n, l;
    Node(int n = 0, int l = 0): n(n), l(l) {}
};
struct Edge{
    int u, v;
    Edge(int u=0, int v=0): u(u), v(v) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add_edge(int u, int v) {
    edges.push_back(Edge(u, v));
    G[u].push_back(edges.size() - 1);
}
void G_init() {
    edges.clear();
    for (int i = 0; i < maxn; i++) {
        G[i].clear();
    }
}

int vis[maxn];
void bfs(int src) {
    memset(vis, 0, sizeof(vis));
    queue<Node> q;
    q.push(Node(src, 0));
    vis[src] = 1;
    int cnt = 0;
    int curl = 0;
    int isf = 1;
    while(!q.empty()) {
        Node u = q.front(); q.pop();
        if (u.l != curl) {
            curl = u.l;
            if (isf) {
                printf("%d", cnt);
                isf = 0;
            } else {
                printf(" %d", cnt);
            }
            cnt = 0;
        } 
        if (G[u.n].size() == 0) cnt++;
        for (int i = 0; i < G[u.n].size(); i++) {
            Edge e = edges[G[u.n][i]];
            if (vis[e.v]) continue;
            q.push(Node(e.v, u.l + 1));
            vis[e.v] = 1;
        }
    }
    if (isf) printf("%d\n", cnt);
    else printf(" %d\n", cnt);
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int N, M;
    scanf("%d%d", &N, &M);
    G_init();
    if (N == 0) return 0;
    for (int i = 0; i < M; i++) {
        int u, v, k;
        scanf("%d%d", &u, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &v);
            add_edge(u, v);
        }   
    }
    bfs(1);
    return 0;
}