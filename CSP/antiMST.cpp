#include <iostream>
#include <queue>

using namespace std;
int n, m, root;
int firstarc[1000005], nextarc[1000005], wiehgt[1000005], adj[1000005];
bool vis[1000005];
struct Edge{
	int no, wieght;
	friend bool operator<(Edge a, Edge b){
		return a.wieght < b.wieght;
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &n, &m, &root);
	int u, v, t;
	memset(firstarc, 0, sizeof(firstarc));
	memset(nextarc, 0, sizeof(nextarc));
	memset(vis, 0, sizeof(vis));
	for(int i=1;i<=m;i++){
		scanf("%d%d%d", &u, &v, &t);
		weight[i] = t;
		nextarc[m] = firstarc[u];
		firstarc[u] = m;
		adj[m] = v;
		weight[i+m] = t;
		nextarc[m+i] = firstarc[v];
		firstarc[v] = m+i;
		adj[m+i] = u;
	}
	priority_queue<Edge> Q;
	Edge tmp;
	int te = firstarc[r];
	while(te){
		tmp.no = te;
		tmp.wieght = wiehgt[te];
		Q.push(tmp);
		te = nextarc[te];
	}
	for(int i=0;i<m-1;i++){
		
	}
}