#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char g[105][105];
int vis[105][105];
int idx, n, m;


void dfs(int i, int j, int idx) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return;
    }
    if (g[i][j] == '*' || vis[i][j] != 0) {
        return;
    }
    vis[i][j] = idx;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++){
            if (dx != 0 || dy != 0) {
                dfs(i + dx, j + dy, idx);
            }
        }
    }
    return;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif

    while(scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        getchar(); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                g[i][j] = getchar();
            }
            getchar();
        }
        memset(vis, 0, sizeof(vis));
        idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '@' && vis[i][j] == 0) {
                    dfs(i, j, ++idx);
                }
            }
        }
        printf("%d\n", idx);
    }

    return 0;
}