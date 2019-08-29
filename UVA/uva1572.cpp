#include <cstdio>
#include <cstring>

int n;
int G[55][55];
int vis[55];
int show_up[55];

int get_no(char a, char b) {
    if (a == '0' && b == '0') return -1;
    return (a - 'A') * 2 + (b == '+'?1:0);
}

int read_case() {
    if (scanf("%d", &n) != 1) return false;
    memset(vis, 0, sizeof(vis));
    memset(show_up, 0, sizeof(show_up));
    memset(G, 0, sizeof(G));
    char s[10];
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int edge[4], cnt = 0;
        for (int k =0; k < 4; k++) {
            int x = get_no(s[2 * k], s[2 * k + 1]);
            if (x != -1) {
                edge[cnt++] = x;
                show_up[x] = 1;
            }
        }
        for (int j = 0; j < cnt; j++) {
            for (int k = j + 1; k < cnt; k++) {  
                //这里的异或及其骚 一般人的思路是把A+/A-产生的变默认加入到图中，但是这样一定会成环
                //因为无向图邻接矩阵总是对称，所以直接把这条边连出去的边进行相连
                //启示 要注意一个图中不同种类的边出现的时候是否会出现异常，应该如何转化
                G[edge[j]^1][edge[k]] = G[edge[k]^1][edge[j]] = 1;
            }
        }
    }
    return true;
}

int dfs(int u) {
    vis[u] = -1;
    for (int v = 0; v < 52; v++) {
        if (G[u][v] && show_up[v]) {
            if (vis[v] == -1) return 0;
            else if (vis[v] == 0 && !dfs(v)) return 0;
        }
    }
    vis[u] = 1;
    return 1;
}

int solve() {
    for (int i = 0; i < 52; i++) {
        if (show_up[i] && !vis[i] && !dfs(i)) return 0;
    }
    return 1;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    while(read_case()) {
        if (!solve()) {
            printf("unbounded\n");
        } else {
            printf("bounded\n");
        }
    }
    return 0;
}