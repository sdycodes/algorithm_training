#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 16385;
struct Edge{
    int u, v;
    Edge(int u=0, int v=0): u(u), v(v) {}
};
vector<Edge> G[maxn];
void init_G() {
    for (int i  = 0; i < maxn; i++) {
        G[i].clear();
    }
}
void add_edge(int u, int v) {
    G[u].push_back(Edge(u, v));
}

map<string, int> na2no;
map<int, string> no2na;
int icnt;

void add_node(string name) {
    na2no[name] = icnt++;
    no2na[icnt - 1] = name;
}
string s;

vector<int> ins_list;
int num[maxn], vis[maxn], is_exp[maxn];

void depend() {
    stringstream ss(s);
    string t;
    ss >> t;
    string src;
    ss >> src;
    if (na2no.find(src) == na2no.end()) {
        add_node(src);
    }
    int nsrc = na2no[src];
    while(ss >> t) {
        if (na2no.find(t) == na2no.end()) {
            add_node(t);
        }
        add_edge(nsrc, na2no[t]);
    }
}

void dfs(int u) {
    vis[u] = 1;
    for (int k = 0; k < G[u].size(); k++) {
        Edge e = G[u][k];
        if (vis[e.v] == 0 && num[e.v] == -1) dfs(e.v);
    }
    printf("   Installing %s\n", no2na[u].c_str());
    num[u] = 0;
    ins_list.push_back(u);
    for (int k = 0; k < G[u].size(); k++) {
        Edge e = G[u][k];
        num[e.v]++;
    }
}

void install() {
    string t, sft;
    stringstream ss(s);
    ss >> t >> sft;
    if (na2no.find(sft) == na2no.end()) {
        add_node(sft);
    }
    if (num[na2no[sft]] != -1) {
        printf("   %s is already installed.\n", sft.c_str());
        return;
    }
    memset(vis, 0, sizeof(vis));
    is_exp[na2no[sft]] = 1;
    dfs(na2no[sft]);
}

void dfs2(int u) {
    vis[u] = 1;
    printf("   Removing %s\n", no2na[u].c_str());
    num[u] = -1;
    ins_list.erase(remove(ins_list.begin(), ins_list.end(), u), ins_list.end());
    for (int k= 0; k < G[u].size(); k++) {
        Edge e = G[u][k];
        num[e.v]--;
        if (vis[e.v] == 0 && num[e.v] == 0 && !is_exp[e.v]) dfs2(e.v);
    }
}

void remove() {
    string t, sft;
    stringstream ss(s);
    ss >> t >> sft;
    int u = na2no[sft];
    if (num[u] > 0) {
        printf("   %s is still needed.\n", sft.c_str());
        return;
    } else if (num[u] == -1) {
        printf("   %s is not installed.\n", sft.c_str());
        return;
    }
    is_exp[u] = 0;
    memset(vis, 0, sizeof(vis));
    dfs2(na2no[sft]);
}

void list() {
    for (int i = 0; i < ins_list.size(); i++) {
        printf("   %s\n", no2na[ins_list[i]].c_str());
    }
}

bool solve() {
    while(getline(cin, s)) {
        printf("%s\n", s.c_str());
        if (s[0] == 'E') return true;
        else if (s[0] == 'D') depend();
        else if (s[0] == 'I') install();
        else if (s[0] == 'R') remove();
        else if (s[0] == 'L') list();
    }
    return false;
}


int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    do {
        init_G();
        na2no.clear();
        no2na.clear();
        icnt = 0;
        ins_list.clear();
        memset(num, -1, sizeof(num));
        memset(is_exp, 0, sizeof(num));
    } while (solve());
    return 0;
}