#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 500
using namespace std;
struct edge{
	int u, v, w, n;
	edge(){};
	edge(int u, int v, int w, int n): u(u), v(v), w(w), n(n){}
};
edge edges[MAXN*MAXN + 5];

int edgecnt;
int node2fe[MAXN + 5];
int dis[MAXN + 5];
bool vis[MAXN + 5];
struct node{
	int u, dis;
	node(int u, int dis):u(u), dis(dis){}
	friend bool operator < (node a, node b) {
		return a.dis > b.dis;
	}
};
void dij(int src, int N) {
	for (int i = 0; i <= N; i++) {
		dis[i] = -1;
		vis[i] = false;
	}
	priority_queue<node> q;
	q.push(node(src, 0));
	dis[src] = 0;
	while(!q.empty()) {
		node tmp = q.top();
		int cur = tmp.u;
		q.pop();
		if (vis[cur]) {
			continue;
		}
		vis[cur] = true;
		int ei = node2fe[cur];
		while(ei != -1) {
			edge e = edges[ei];
			if (dis[e.v] == -1 || dis[e.v] > dis[cur] + e.w) {
				dis[e.v] = dis[cur] + e.w;
				q.push(node(e.v, dis[e.v]));
			}
			ei = e.n;
		}
	}
}

int main(int argc, char *argv[]) {
	int N, Q;
	while(scanf("%d%d", &N, &Q) != EOF) {
		edgecnt = 0;
		memset(node2fe, -1, sizeof(node2fe));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int w;
				scanf("%d", &w);
				if (w != -1) {
					edges[edgecnt++] = edge(i, j, w, node2fe[i]);
					node2fe[i] = edgecnt - 1;
				}
			}
		}
		for (int i = 1; i <= Q; i++) {
			int src, dst;
			scanf("%d%d", &src, &dst);
			if (src == dst) {
				printf("jujue\n");
				continue;
			}
			dij(src, N);
			if (dis[dst] != -1) {
				printf("%d\n", dis[dst]);
			} else {
				printf("jujue\n");
			}
		}
	}
}