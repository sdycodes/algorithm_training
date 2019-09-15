#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 105;
const int maxm = 105;
const int maxb = 105;
int dis[maxn][maxm][maxb];
int a[maxn][maxm], b[maxn][maxm];
int board[maxn][maxm];
int n, m;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

struct Node{
    int r, c, t;
    Node(int r = 0, int c = 0, int t = 0): r(r), c(c), t(t) {}
};

int is_in(int r, int c) {
    return r >= 1 && r <= n && c >= 1 && c <= m;
}

int is_safe(int r, int c, int t) { 
    return !board[r][c] || t < a[r][c] || t > b[r][c];
}

int bfs(int sr, int sc, int er, int ec) {
    queue<Node> q;
    memset(dis, -1, sizeof(dis));
    dis[sr][sc][0] = 0;
    while(!q.empty()) {
        Node u = q.front(); q.pop();
        if (u.r == er && u.c == ec) return u.t;
        int ispush = 0;
        for (int i = 0; i < 4; i++) {
            int nr = u.r + dr[i];
            int nc = u.c + dc[i];
            if (!is_in(nr, nc)) continue;
            int nt = u.t + 1 > b[nr][nc]?101:(u.t + 1);
            int ot = u.t > b[u.r][u.c]? 101:u.t;
            if (!board[nr][nc]) nt = 101;
            if (!board[u.r][u.c]) ot = 101;
            if (dis[nr][nc][nt] == -1 && is_safe(nr, nc, u.t + 1)) {
                dis[nr][nc][nt] = dis[u.r][u.c][ot] + 1;
                q.push(Node(nr, nc, u.t + 1));
                ispush = 1;
            }
        }
    }
    return -1;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    memset(board, 0, sizeof(board));
    int danger;
    scanf("%d%d%d", &n, &m, &danger);
    for (int i =0; i < danger; i++) {
        int r, c, start, end;
        scanf("%d%d%d%d", &r, &c, &start, &end);
        board[r][c] = 1;
        a[r][c] = start;
        b[r][c] = end;
    }
    printf("%d\n", bfs(1, 1, n, m));
    return 0;
}