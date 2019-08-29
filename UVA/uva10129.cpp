#include <cstdio>
#include <cstring>

int G[26][26], vis[26];
int in[26], out[26];
int show_up[26];

void read_case() {
    int e;
    scanf("%d", &e);
    getchar();
    memset(G, 0, sizeof(G));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(show_up, 0, sizeof(show_up));
    char s[1005];
    while(e--) {
        fgets(s, 1003, stdin);
        int u = s[0] - 'a';
        int v = s[strlen(s) - 1] == '\n'? s[strlen(s) - 2] - 'a': s[strlen(s) - 1] - 'a';
        G[u][v] = G[v][u] = 1;
        out[u]++;
        in[v]++;
        show_up[u] = show_up[v] = 1;
    }
    //init
    memset(vis, 0, sizeof(vis));
}

void dfs(int u) {
    vis[u] = 1;
    for (int v = 0; v < 26; v++) {
        if (G[u][v] && !vis[v]) {
            dfs(v);
        }
    }
}

int is_connected() {
    for (int i = 0; i < 26; i++) {
        if (show_up[i]) {
            dfs(i);
            break;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!vis[i] && show_up[i])  return 0;
    }
    return 1;
}

int is_Euler() {
    int src = 0, dst = 0;
    for (int i = 0; i < 26; i++) {
        if (in[i] == out[i]) continue;
        if (in[i] - out[i] == 1) {
            src++;
        } else if (out[i] - in[i] == 1) {
            dst++;
        } else {
            return 0;
        }
    }
    return (src == 0 && dst == 0) || (src == 1 && dst == 1);
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    while(T--) {
        read_case();
        if (is_connected() && is_Euler()) {
            printf("Ordering is possible.\n");
        } else {
            printf("The door cannot be opened.\n");
        }
    }

    return 0;
}