#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct Node{
    int x, y;
    Node(int x=0, int y=0): x(x), y(y) {}  
};

const int maxn = 105;
const int maxm = 105;
char board[maxn][maxm];
int vis[maxn][maxm];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, q;

int islegal(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n && board[y][x] != '-' && board[y][x] != '|' && board[y][x] != '+';
}

void draw_line(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        // x1 == x2 var r
        int c = x1;
        y1 = n - 1 - y1;
        y2 = n - 1 - y2;
        if (y1 > y2) {
            int t = y1;
            y1 = y2;
            y2 = t;
        }
        for (int r = y1; r <= y2; r++) {
            if (board[r][c] == '-') {
                board[r][c] = '+';
            } else if (board[r][c] != '+') {
                board[r][c] = '|';
            }
        }
    } else {
        // y1 == y2 var c
        int r = n - 1 - y1;
        if (x1 > x2) {
            int t = x1;
            x1 = x2;
            x2 = t;
        }
        for (int c = x1; c <= x2; c++) {
            if (board[r][c] == '|') {
                board[r][c] = '+';
            } else if (board[r][c] != '+') {
                board[r][c] = '-';
            }
        }
    }
}

void fill(int x, int y, char c) {
    queue<Node> qu;
    memset(vis, 0, sizeof(vis));
    y = n - 1 - y;
    qu.push(Node(x, y));
    board[y][x] = c;
    vis[y][x] = 1;
    while(!qu.empty()) {
        Node u = qu.front(); qu.pop();
        for (int i = 0; i < 4; i++) {
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if (!vis[ny][nx] && islegal(nx, ny)) {
                board[ny][nx] = c;
                vis[ny][nx] = 1;
                qu.push(Node(nx, ny));
            }
        }
    }
    return;
}

void show() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    scanf("%d%d%d", &m, &n, &q);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = '.';
        }
    }
    for (int i = 0; i < q; i++) {
        int op;
        scanf("%d", &op);
        if (!op) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            draw_line(x1, y1, x2, y2);
        } else {
            int x, y;
            char c;
            scanf("%d%d", &x, &y);
            getchar();
            c = getchar();
            fill(x, y, c);
        }
        //show();
    }
    show();
    return 0;
}