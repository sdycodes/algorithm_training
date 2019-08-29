#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
const int maxn = 10005;
struct Edge{
    int u, v, w;
    Edge(int u=0,int v=0, int w=0): u(u), v(v), w(w) {}
};

vector<Edge> G[maxn];
void add_edge(int u, int v, int w) {
    G[u].push_back(Edge(u, v, w));
}
void init_G() {
    for (int i = 0; i < maxn; i++) {
        G[i].clear();
    }
}
long long dis[maxn];

int read_case() {
    init_G();
    string s;
    int cnt = 0;
    while(getline(cin, s)) {
        if (s.length() == 0) break;
        int u, v, w;
        cnt++;
        sscanf(s.c_str(), "%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    return cnt;
}

void bfs(int u) {
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    q.push(u);
    dis[u] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            Edge e = G[u][i];
            if (dis[e.v] == -1) {
                dis[e.v]  =dis[u] + e.w;
                q.push(e.v);
            }
        }
    }
}

long long solve() {
    bfs(1);
    long long maxd = 0, ridx = -1;
    for (int i = 0; i < maxn; i++) {
        if (dis[i] > maxd) {
            maxd = dis[i];
            ridx = i;
        }
    }
    bfs(ridx);
    for (int i = 0; i < maxn; i++) {
        if (dis[i] > maxd) {
            maxd = dis[i];
        }
    }
    return maxd;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif 
    while(read_case()) {
        printf("%lld\n", solve());
    }
    return 0;
}