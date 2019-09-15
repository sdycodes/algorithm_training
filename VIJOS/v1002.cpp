#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
 int L, S, T, M;
const int maxn = 105;
const int maxL = 1e9;
bool stone[maxL];
int x[maxn];

int vis[maxn], dis[maxn];

void bfs() {
    memset(vis, 0, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    dis[0] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 1; i <= M + 1; i++) {
            if (g[u][i] == 1 && !vis[i]) {
                dis[i] = dis[u] + 1;
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return;
}
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    scanf("%d%d%d%d", &L, &S, &T, &M);
    memset(stone, 0, sizeof(stone));
    for (int i = 0; i < M; i++) {
        scanf("%d", &x[i]);
        stone[x[i]] = true;
    }
    dij();
    return 0;
}