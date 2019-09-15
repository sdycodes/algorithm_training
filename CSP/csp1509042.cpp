#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 10005;
//scc_cnt记录强连通分量的个数，初始化是0但是是从1开始的 最后是1～ssc_cnt
int dfs_clock, scc_cnt;
//sccno[u]记录点u属于第几个强联通分量，即点u所在强联通分量的编号
int pre[maxn], lowlink[maxn], sccno[maxn];
//scc[i]记录第i个强连通分量有哪些点
vector<int> g[maxn], scc[maxn];
//保存当前强连通分量中的点
stack<int> s;

void G_init() {
    for (int i = 0; i < maxn; ++i)
        g[i].clear();
}

void dfs(int u) {
    pre[u] = lowlink[u] = ++dfs_clock;
    s.push(u);
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (0 == pre[v]) {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (0 == sccno[v]) {
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }
    if (lowlink[u] == pre[u]) {
        ++scc_cnt;//从1开始
        scc[scc_cnt].clear();
        while (1) {
            int x = s.top();
            s.pop();
            sccno[x] = scc_cnt;
            scc[scc_cnt].push_back(x);
            if (x == u) break;
        }
    }
}

void find_scc(int n) {
    dfs_clock = scc_cnt = 0;
    memset(pre, 0, sizeof(pre));
    memset(sccno, 0, sizeof(sccno));
    for (int i = 1; i <= n; ++i) {  //点编号从1开始
        if (0 == pre[i]) dfs(i);
    }
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    G_init();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }
    find_scc(n);
    long long res = 0;
    for (int i = 1; i <= scc_cnt; i++) {
        res += (scc[i].size() * (scc[i].size() - 1)) / 2;
    }
    printf("%lld\n", res);
    return 0;
}
