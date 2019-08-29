#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int maxm = 105;
const int maxn = 1 << 21;
int n, m;
struct Edge{
    int w;
    char s1[30], s2[30];
}edges[maxm];

struct Node{
    int n, w;
    Node(int n=0, int w= 0): n(n), w(w) {}
    bool operator<(const Node& b) const {
        return w > b.w;
    }
};

int dis[maxn], vis[maxn];

int adjne(int n, char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] != '0') {
            if (s[i] == '+' && !(n & (1 << (len - i - 1)))) {
                return 0;
            }
            if (s[i] == '-' && ((n | ~(1 << (len - i - 1))) == 0xffffffff)) {
                return 0;
            }
        }
    }
    return 1;
}



int get_adjn(char s[], int cur) {
    int res = 0;
    for (int i = 0; i < strlen(s); i++) {
        int pos = 1 << (n - i - 1);
        if (s[i] == '+') {
            res |= pos;
        } else if (s[i] == '0'){
            res |= (cur & pos);
        }
    }
    return res;
}

void dij() {
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<Node> q;
    int src = (0xfffff) >> (20 - n);
    q.push(Node(src, 0));
    dis[src] = 0;
    while(!q.empty()) {
        Node u = q.top(); q.pop();
        if (u.n == 0) break;
        if (vis[u.n]) continue;
        vis[u.n] = 1;
        for (int e = 0; e < m; e++) {
            if (adjne(u.n, edges[e].s1)) {
                int v = get_adjn(edges[e].s2, u.n);
                if (dis[v] == -1 || dis[v] > dis[u.n] + edges[e].w) {
                    dis[v] = dis[u.n] + edges[e].w;
                    q.push(Node(v, dis[v]));
                }
            }
        }
    }
    return;
}

int main() {
    #ifdef D
       freopen("data.in", "r", stdin);
    #endif
    int kase = 0;
    while(scanf("%d%d", &n, &m) != EOF) {
        if (m == 0 && n == 0) break;
        kase++;
        for (int i = 0; i < m; i++) {
            scanf("%d%s%s", &edges[i].w, edges[i].s1, edges[i].s2);
        }
        printf("Product %d\n", kase);
        dij();
        if (dis[0] == -1) printf("Bugs cannot be fixed.\n");
        else printf("Fastest sequence takes %d seconds.\n", dis[0]);
        printf("\n");
    }
    return 0;
}
