#include <cstdio>
#include <cstring>

using namespace std;
// 1 dfs找topo 不一定非要从最大的找  设置标记自动删图
// 2 判断是否有环 提高鲁棒性
// 3 判断加执行的特殊技巧

const int maxn = 105;
int n, m;
int G[maxn][maxn], topo[maxn], pos, vis[maxn];

int read_case() {
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0) return false;
    memset(G, 0, sizeof(G));
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a][b] = 1;
    }
    //init
    memset(vis, 0, sizeof(vis));
    pos = n;
    return true;
}

int dfs(int u) {
    vis[u] = -1;
    for (int i = 1; i <= n; i++) {
        if (G[u][i]) {  //先判断连通性  邻接表可以加速
            if (vis[i] < 0) return 0;  //出现环返回
            else if (!vis[i] && !dfs(i)) return 0; //不出现环但是继续dfs出现环
            //这个地方  判断和执行一起写 极高的技巧性
        }
    }
    vis[u] = 1;
    topo[pos--] = u;
    return 1;
}

int topo_sort() {
    for (int i = 1; i <= n; i++) {  //这个不能少  应对多个连通分量
        if (!vis[i]) {
            if (!dfs(i)) return 0; //这个点在环上，不存在topo
        }
    }
    return 1;
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    while(read_case()) {
        if (topo_sort()) {
            printf("%d", topo[1]);
            for (int i = 2; i <= n; i++) {
                printf(" %d", topo[i]);
            }
            printf("\n");
        } else {
            printf("\n");
        }
    }
    return 0;
}