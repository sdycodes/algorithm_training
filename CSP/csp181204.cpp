#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 50005;
const int maxm = 50005;
int p[maxn];
void S_init(){
    for (int i = 0; i < maxn; i++) {
        p[i] = i;
    }
}
int find(int x) {
    return x == p[x] ? x: p[x] = find(p[x]);
}
void cup(int rep1, int rep2) {
    p[rep1] = rep2;
}
struct Edge{
    int u, v, t;
    Edge(int u=0, int v=0, int t=0):u(u), v(v), t(t) {}
    bool operator<(const Edge& rhs) const {
        return t < rhs.t;
    }
};
vector<Edge> edges;
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int n, m, r;
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        edges.push_back(Edge(u, v, t));
    }
    S_init();
    sort(edges.begin(), edges.end());
    int choose = 0;
    int maxm = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v;
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            maxm = max(maxm, edges[i].t);
            cup(pu, pv);
            choose++;
            if (choose == n - 1) break;
        }
    }
    printf("%d\n", maxm);
    return 0;
}