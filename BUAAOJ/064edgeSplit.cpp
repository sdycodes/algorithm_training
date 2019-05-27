#include <iostream>
#include <queue>
#define MAXN 100
using namespace std;
struct Edge{
	int u, v, w, n;
	Edge(){}
	Edge(int u, int v, int w, int n):u(u), v(v), w(w), n(n){}
};
Edge edges[MAXN*MAXN*MAXN + MAXN + 5];
int edgecnt;
int dis[MAXN * MAXN + 5];
int fn[MAXN * MAXN + 5];
int p[MAXN+5][MAXN+5];
int t[MAXN+5][MAXN+5];
struct Node{
	int u, d;
	Node(int u, int d):u(u), d(d){}
	Node(){}
	friend bool operator < (Node a, Node b) {
		return a.d > b.d;
	}
};

void dij(int src) {
	bool vis[MAXN * MAXN + 5];
	for (int i = 0; i <MAXN * MAXN + 5; i++) {
		vis[i] = false;
		dis[i] = -1;
	}
	priority_queue<Node> q;
	dis[src] = 0;
	q.push(Node(src, dis[src]));
	while(!q.empty()) {
		Node tmp = q.top();
		q.pop();
		int cur = tmp.u;
		if (vis[cur]) {
			continue;
		}
		vis[cur] = true;
		int e = fn[cur];
		while(e != -1) {
			if (dis[edges[e].v] == -1 || dis[edges[e].v] > dis[cur] + edges[e].w) {
				dis[edges[e].v] = dis[cur] + edges[e].w;
				q.push(Node(edges[e].v, dis[edges[e].v]));
			}
			e = edges[e].n;
		}
	}
	return;
}

int main(int argc, char *argv[]) {
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF) {
		//input
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &p[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &t[i][j]);
			}
		}
		//init
		for (int i = 0; i < MAXN*MAXN + 5; i++) {
			fn[i] = -1;
		}
		edgecnt = 0;
		//build
		for (int i = 0; i < n; i++) {
			edges[edgecnt++] = Edge(0, i * 100 + 1, p[i][1], fn[0]);
			fn[0] = edgecnt - 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) {
				int u = i * 100 + j;
				for (int k = 0; k < n; k++) {
					int v = k * 100 + j + 1;
					edges[edgecnt++] = Edge(u, v, p[k][j + 1] + t[i][k], fn[u]);
					fn[u] = edgecnt - 1;
				}
			}
		}
		//cal
		dij(0);
		int min = -1;
		for (int i = 0; i < n; i++) {
			if (min == -1 || min > dis[i * 100 + m]) {
				min = dis[i * 100 + m];
			}
		}
		printf("%d\n", min);
	}
}