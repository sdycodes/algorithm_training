#include <stdio.h>
#include <string.h>

#define maxn 100005
#define maxc 1000000005
#define maxe 400005
int n, m;

struct Queue {
    int front, back, len;
    int a[maxn];
};
typedef struct Queue queue;

int empty_q(queue q) {
    return q.front == q.back;
}

void init_q(queue* q, int len) {
    q->front = 0;
    q->back = 0;
    q->len = len;
}

void pop_q(queue* q) {
    q->front = (q->front + 1) % q->len;
}

void push_q(queue* q, int ele) {
    q->a[q->back] = ele;
    q->back = (q->back + 1) % q->len;
}
int front_q(queue q) {
    return q.a[q.front];
}

struct Edge {
    int u, v, c, n;
} edges[maxe];
int edge_num, node_num;
int fe[maxn];

int dis[maxn], vis[maxn];

void G_init() {
    edge_num = 0;
    node_num = 0;
    memset(fe, -1, sizeof(fe));
}

void add_edge(int u, int v, int c) {
    edges[edge_num].u = u;
    edges[edge_num].v = v;
    edges[edge_num].c = c;
    edges[edge_num].n = fe[u];
    fe[u] = edge_num++;
}

int read_case() {
    if (scanf("%d%d", &n, &m) != 2) return 0;
    G_init();
    int u, v, c;
    int i;
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        add_edge(u, v, c);
        add_edge(v, u, c);
    }
    return 1;
}

void bfs_r(int src, int dst) {
    memset(dis, -1, sizeof(dis));
    queue q;
    init_q(&q, maxn - 1);
    push_q(&q, src);
    dis[src] = 0;
    while(!empty_q(q)) {
        int u = front_q(q); pop_q(&q);
        if (u == dst) break;
        int e;
        for (e = fe[u]; e != -1; e = edges[e].n) {
            int v = edges[e].v;
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                push_q(&q, v);
            }
        }
    }
    return;
}

int path[maxn], pos;
int next[maxn], cnt;
int tmp[maxn], tcnt;
void bfs_multi(int src) {
    pos = 0;
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    next[cnt++] = src;
    vis[src] = 1;
    int i;
    for (i = 0; i < dis[src]; i++) {
        int min_c = maxc;
        int j;
        for (j = 0; j < cnt; j++) {
            int u = next[j];
            int e;
            for (e = fe[u]; e != -1; e = edges[e].n) {
                int v = edges[e].v;
                if (dis[u] == dis[v] + 1) {
                    min_c = (min_c <= edges[e].c?min_c:edges[e].c);
                }
            }
        }
        path[pos++] = min_c;
        tcnt = 0;
        for (j = 0; j < cnt; j++) {
            int u = next[j];
            int e;
            for (e = fe[u]; e != -1; e = edges[e].n) {
                int v = edges[e].v;
                if (dis[u] == dis[v] + 1 && !vis[v] && min_c == edges[e].c) {
                    vis[v] = 1;
                    tmp[tcnt++] = v;
                }
            }
        }
        memcpy(next, tmp, sizeof(int) * tcnt);
        cnt = tcnt;
    }
    return;
}

void solve() {
    bfs_r(n, 1);
    pos = 0;
    bfs_multi(1);
    printf("%d\n%d", pos, path[0]);
    int i;
    for (i = 1; i < pos; i++) {
        printf(" %d", path[i]);
    }
    printf("\n");
}

int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    while(read_case()) {
        solve();
    }
    return 0;
}