#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>



using namespace std;

const int maxn = 30;
int n, m;
map<string, int> name2id;

struct Node{
    int id;
    string name;
    Node(int id, string name): id(id), name(name) {}
};
vector<Node> nodes;

int get_id(string name) {
    if (name2id.find(name) == name2id.end()) {
        nodes.push_back(Node(nodes.size(), name));
        name2id[name] = nodes.size() - 1;
    }
    return name2id[name];
}

int g[maxn][maxn];

void floyed() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
            }
        }
    }
}

int ng[maxn][maxn];

void build_newg() {
    memset(ng, 0, sizeof(ng));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (g[i][j] && g[j][i]) {
                ng[i][j] = 1;
                ng[j][i] = 1;
            }
        }
    }
}

int vis[maxn], group[maxn];

void bfs(int src, int color) {
    queue<int> q;
    vis[src] = 1;
    group[src] = color;
    q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < n; v++) {
            if (ng[u][v] && !vis[v]) {
                q.push(v);
                vis[v] = 1;
                group[v] = color;
            }
        }
    }
    return;
}

void output(int kase) {
    if (kase != 1) printf("\n");
    printf("Calling circles for data set %d:\n", kase);
    vector<int> lines[n];
    for (int i = 0; i < n; i++) {
        lines[group[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (lines[i].size() != 0) {
            printf("%s", nodes[lines[i][0]].name.c_str());
            for (int j = 1; j < lines[i].size(); j++) {
                printf(", %s", nodes[lines[i][j]].name.c_str());
            }
            printf("\n");
        }
    }
}


int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int kase = 0;
    while(scanf("%d%d", &n, &m)) {
        kase++;
        if (n == 0 && m == 0) break;
        memset(g, 0, sizeof(g));
        name2id.clear();
        nodes.clear();
        string from, to;
        for (int i = 0; i < m; i++) {
            cin >> from >> to;
            g[get_id(from)][get_id(to)] = 1;
        }
        floyed();
        build_newg();
        memset(vis, 0, sizeof(vis));
        memset(group, 0, sizeof(group));
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) bfs(i, c++);
        }
        output(kase);
    }
    return 0;
}