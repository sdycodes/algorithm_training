#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct Node {
    int r, c, k;
    Node(int r=0, int c=0, int k=0): r(r), c(c), k(k) {}
};

const int maxn = 25;
int m, n, k;
int G[maxn][maxn];
int dis[maxn][maxn][maxn], vis[maxn][maxn][maxn];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int inside(int r, int c) {
    return r >= 1 && r <= m && c >= 1 && c <= n;
}
int can_pan(int r, int c, int nk) {
    return nk + 1 <= k;
}
int bfs() {
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<Node> q;
    q.push(Node(1, 1, 0));
    dis[1][1][0] = 0;
    vis[1][1][0] = 1;
    while(!q.empty()) {
        Node u = q.front(); q.pop();
        if (u.r == m && u.c == n) return dis[u.r][u.c][u.k];
        for (int i = 0; i < 4; i++) {
            int nr = u.r + dr[i], nc = u.c + dc[i];
            if (!inside(nr, nc)) continue;
            int nk;
            if (G[nr][nc] == 0) {
                nk = 0;
            } else {
                if (u.k + 1 <= k) nk = u.k + 1;
                else continue;
            }
            if (vis[nr][nc][nk]) continue;
            dis[nr][nc][nk] = dis[u.r][u.c][u.k] + 1;
            vis[nr][nc][nk] = 1;
            q.push(Node(nr, nc, nk));
        }
    }
    return -1;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &m, &n, &k);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &G[i][j]);
            }
        }
        printf("%d\n", bfs());
    }
    return 0;
}