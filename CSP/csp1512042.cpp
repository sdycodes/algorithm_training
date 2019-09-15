#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>


using namespace std;

const int maxn = 10005;
const int maxm = 100005;
int n, m;
struct Edge{
    int u, v, n;
    Edge(int u=0, int v=0, int n=0): u(u), v(v), n(n) {}
    bool operator<(const Edge& b) const {
        return v < b.v;
    }
};
vector<Edge> G[maxn];
int degree[maxn];

void G_init() {
    for (int i = 0; i < maxn; i++) {
        G[i].clear();
    }    
}

void add_edge(int u, int v, int n) {
    G[u].push_back(Edge(u, v, n));
}

int vis[maxm];

int dfs(int u, vector<int>& path, int& cnt) {
    path.push_back(u);
    if (cnt == m) return 1;
    for (int k = 0; k < G[u].size(); k++) {
        Edge& e = G[u][k];
        if (!vis[e.n]) {
            vis[e.n] = 1;
            cnt++;
            if (dfs(e.v, path, cnt)) {
                return 1;
            }
            cnt--;
            vis[e.n] = 0;
        }
    }
    path.pop_back();
    return 0;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    scanf("%d%d", &n, &m);
    G_init();
    memset(degree, 0, sizeof(degree));
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v, i);
        add_edge(v, u, i);
        degree[u]++;
        degree[v]++;
    }
    int odd_num = 0;
    int end = -1;
    for (int i = 2; i <= n; i++) {
        if (degree[i] % 2) {
            odd_num++;
            end = i;
            if (odd_num >= 2) break;
        }
    }
    if (odd_num >= 2) {
        printf("-1\n");
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        sort(G[i].begin(), G[i].end());
    }
    memset(vis, 0, sizeof(vis));
    vector<int> path;
    int cnt = 0;
    dfs(1, path, cnt);
    for (int i = 0; i < path.size(); i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
    return 0;
}