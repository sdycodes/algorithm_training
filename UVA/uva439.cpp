#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct Node{
    int r, c;
    Node(int r = 0, int c = 0): r(r), c(c){}
};
int vis[10][10], dis[10][10];
int dr[] = {1, -1, 1, -1, 2, -2, 2, -2};
int dc[] = {2, 2, -2, -2, 1, 1, -1, -1};

int r0, c0, r1, c1;

int inside(int r, int c) {
    return r >= 1 && r <= 8 && c >= 1 && c <= 8;
}

void bfs(int r, int c) {
    queue<Node> q;
    memset(vis, 0, sizeof(vis));
    q.push(Node(r, c));
    dis[r][c] = 0;
    vis[r][c] = 1;
    while(!q.empty()) {
        Node t = q.front(); q.pop();
        if (t.r == r1 && t.c == c1) break;
        for (int i = 0; i < 8; i++) {
            int nr = t.r + dr[i];
            int nc = t.c + dc[i];
            if (inside(nr, nc) && !vis[nr][nc]) {
                dis[nr][nc] = dis[t.r][t.c] + 1;
                vis[nr][nc] = 1;
                q.push(Node(nr, nc));
            }
        }
    }
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    char t0, t1;
    while(scanf("%c%d %c%d", &t0, &r0, &t1, &r1)!=EOF) {
        getchar();
        c0 = t0 - 'a' + 1;
        c1 = t1 - 'a' + 1;
        bfs(r0, c0);
        printf("To get from %c%d to %c%d takes %d knight moves.\n", t0, r0, t1, r1, dis[r1][c1]);
    }
    return 0;
}