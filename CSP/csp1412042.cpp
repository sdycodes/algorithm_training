#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 1005;
struct Edge{
    int u, v, w;
    Edge(int u=0, int v = 0, int w = 0): u(u), v(v), w(w){}
    bool operator<(const Edge b) const {
        return w < b.w;
    }
};
vector<Edge> edges;

void G_init() {
    edges.clear();
}
void add_edge(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
}

int pre[maxn];
void S_init() {
    for (int i = 0; i < maxn; i++) {
        pre[i] = i;
    }
}
int find(int x) {
    return x == pre[x]?x: pre[x] = find(pre[x]);
}
void cup(int rep1, int rep2) {
    pre[rep1] = rep2;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n, m;
    G_init();
    S_init();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
    }
    sort(edges.begin(), edges.end());
    int cnt = 0;
    int res = 0;
    for (int i = 0; i < edges.size(); i++) {
        int rep1 = find(edges[i].u);
        int rep2 = find(edges[i].v);
        if (rep1 != rep2) {
            cnt++;
            cup(rep1, rep2);
            res += edges[i].w;
        }
        if (cnt == n - 1) break;
    }
    printf("%d\n", res);
    return 0;
}