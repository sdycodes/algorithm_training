#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

// 初始化问题（注意范围） 平行边问题
// 第一遍必须反向 不然可能错入非最短路
// 第二遍 vis不能少 否则出现同一轮次被多次入队的情况

using namespace std;

const int maxn = 100005;
const int maxc = 1000000005;
const int maxe = 400005;

// 注意加边的时候，一定要保证G[a]里的边e 满足e.u==a
// 注意每一轮次都要初始化
int n, m;
struct Edge {
    int u, v, c;
    Edge(int u=0, int v = 0, int c = 0): u(u), v(v), c(c) {}
};
vector<Edge> G[maxn];
void G_init(int n) {
    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }
}
void add_edge(int u, int v, int c) {
    G[u].push_back(Edge(u, v, c));
}
int dis[maxn];
int vis[maxn];

int read_case() {
    if (scanf("%d%d", &n, &m) != 2) return 0;
    G_init(n);
    int u, v, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        add_edge(u, v, c);
        add_edge(v, u, c);
    }
    return 1;
}

// 反向bfs的作用  得到的距离是每个点到终点的距离
// 这个性质极为重要 可以避免接下来正向的时候误入歧途
void bfs_r(int src, int dst) {
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if (u == dst) break; 
        for (int k = 0; k < (int)G[u].size(); k++) {
            Edge e = G[u][k];
            if (dis[e.v] == -1) {
                dis[e.v] = dis[u] + 1;
                q.push(e.v);
            }
        }
    }
    return;
}

void bfs_multi(vector<int>& path, int src) {
    vector<int> next;
    memset(vis, 0,sizeof(vis));
    path.clear();
    next.push_back(src);
    vis[src] = 1;
    // 一共要走dis[1]步 也就是1～n的距离
    for (int i = 0; i < dis[src]; i++) {
        int min_c = maxc;
        //next 是当前探索的最前沿
        for (int j = 0; j < (int)next.size(); j++) {
            int u = next[j];
            for (int k = 0; k < (int)G[u].size(); k++) {
                Edge e = G[u][k];
                if (dis[u] == dis[e.v] + 1) { //有dis作保证 不需要考虑vis
                    min_c = (min_c <= e.c?min_c : e.c);
                }
            }
        }
        path.push_back(min_c);
        vector<int> next2;
        for (int j = 0; j < (int)next.size(); j++) {
            int u = next[j];
            for (int k = 0; k < (int)G[u].size(); k++) {
                Edge e = G[u][k];
                // 这里必须有vis 有的点可能被当前的前沿多次指，没有vis会重复入队
                if (dis[u] == dis[e.v] + 1 && !vis[e.v] && e.c == min_c) {
                    vis[e.v] = 1;
                    next2.push_back(e.v);
                }
            }
        }
        next = next2;
    }
    return;
}

void solve() {
    bfs_r(n, 1);
    vector<int> path;
    bfs_multi(path, 1);
    printf("%d\n%d", (int)path.size(), path[0]);
    for (int i = 1; i < (int)path.size(); i++) {
        printf(" %d", path[i]);
    }
    printf("\n");
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    while(read_case()) {
        solve();
    }
    return 0;
}