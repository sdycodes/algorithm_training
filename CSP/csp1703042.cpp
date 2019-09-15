#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100005;

struct Edge{
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w) {}
    bool operator<(const Edge& b) const {
        return w < b.w;
    }
};

vector<Edge> edges;
vector<int> G[maxn];

void add_edge(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    G[u].push_back(edges.size() - 1);
}

void G_init() {
    edges.clear();
    for (int i = 0; i < maxn; i++) {
        G[i].clear();
    }
}

int p[maxn];
int find(int x) {
    return p[x] == x? x: p[x] = find(p[x]);
}
void cup(int rep1, int rep2) {
    p[rep1] = rep2;
}

void cal_mst(vector<Edge>& mste, int n) {
    mste.clear();
    for (int i = 0; i < maxn; i++) {
        p[i] = i;
    }
    sort(edges.begin(), edges.end());
    int cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int rep1 = find(u);
        int rep2 = find(v);
        if (rep1 != rep2) {
            mste.push_back(edges[i]);
            cup(rep1, rep2);
            cnt++;
            if (cnt == n - 1) break;
        } 
    }
}

int dis[maxn];

void bfs(int src, int n) {
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if (u == n) break;
        for (int k = 0; k < G[u].size(); k++) {
            Edge& e = edges[G[u][k]];
            if (dis[e.v] == -1) {
                dis[e.v] = max(dis[e.u], e.w);
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
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges.push_back(Edge(u, v, w));
    }
    vector<Edge> mste;
    cal_mst(mste, n);
    G_init();
    for (int i = 0; i < mste.size(); i++) {
        add_edge(mste[i].u, mste[i].v, mste[i].w);
        add_edge(mste[i].v, mste[i].u, mste[i].w);
    }
    bfs(1, n);
    printf("%d\n", dis[n]);
    return 0;
}