#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int r, c, d;
    Node(int r=0, int c=0, int d=0):r(r), c(c), d(d) {}
};

const char dirs[] = "NESW";
const char turns[] = "FLR";
const int maxn = 10;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int has_edge[maxn][maxn][4][3];
Node pre[maxn][maxn][4];
int dis[maxn][maxn][4];

char name[100];
int r0, c0, r1, c1, r2, c2, dir, dir2;

int dir_no(char c) { return strchr(dirs, c) - dirs; }
int turn_no(char c) { return strchr(turns, c) - turns; }

Node walk(Node cur, int turn) {
    int new_d = cur.d;
    if (turn == 1)  new_d = (new_d + 3) % 4;
    if (turn == 2)  new_d = (new_d + 1) % 4;
    return Node(cur.r + dr[new_d], cur.c + dc[new_d], new_d);
}

bool is_inside(Node t) {
    return t.c <= 9 && t.c >= 1 && t.r >= 1 && t.r <= 9;
}

bool read_case() {
    memset(has_edge, 0, sizeof(has_edge));
    memset(dis, -1, sizeof(dis));

    char s[10];
    if (scanf("%s%d%d%s%d%d", name, &r0, &c0, s, &r2, &c2) != 6) {
        return false;
    }
    dir = dir_no(s[0]);
    r1 = r0 + dr[dir];
    c1 = c0 + dc[dir];

    int tr, tc;
    while(scanf("%d", &tr) && tr) {
        scanf("%d", &tc);
        while(scanf("%s", s) && s[0] != '*') {
            int tdir = dir_no(s[0]);
            for (int i = 1; i < strlen(s); i++) {
                has_edge[tr][tc][tdir][turn_no(s[i])] = 1;
            }
        }
    }
    return true;
}


bool solve() {
    queue<Node> q;
    q.push(Node(r1, c1, dir));
    dis[r1][c1][dir] = 0;
    while(!q.empty()) {
        Node t = q.front();
        q.pop();
        if (t.r == r2 && t.c == c2) {
            dir2 = t.d;
            return true;
        }
        for (int i = 0; i < 3; i++) {
            Node new_node = walk(t, i);
            if (is_inside(new_node) && has_edge[t.r][t.c][t.d][i] && 
                    dis[new_node.r][new_node.c][new_node.d] == -1) {
                dis[new_node.r][new_node.c][new_node.d] = dis[t.r][t.c][t.d] + 1;
                pre[new_node.r][new_node.c][new_node.d] = t;
                q.push(new_node);
            }
        }
    }
    return false;
}

void output() {
    vector<Node> track;
    Node tmp = Node(r2, c2, dir2);  
    while(1) {
        track.push_back(tmp);
        if (dis[tmp.r][tmp.c][tmp.d] == 0) break;
        tmp = pre[tmp.r][tmp.c][tmp.d];
    }
    track.push_back(Node(r0, c0, dir));
    int cnt = 0;
    for (int i = track.size() - 1; i >= 0; i--) {
        cnt++;
        if (cnt == 1) putchar(' ');
        printf(" (%d,%d)", track[i].r, track[i].c);
        if (cnt == 10) {
            putchar('\n');
            cnt = 0;
        }
    }
    if (cnt != 0) putchar('\n');
    return;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    while(read_case()) {
        printf("%s\n", name);
        if (solve()) {
            output();
        }
        else {
            printf("  No Solution Possible\n");
        }
    }
    return 0;
}