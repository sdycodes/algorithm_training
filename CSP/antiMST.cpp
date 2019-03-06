#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int firstarc[1000005], nextarc[1000005], weight[1000005], adj[1000005];
bool vis[1000005];
struct Edge{
	int no, weight;
	friend bool operator<(Edge a, Edge b){
		return a.weight > b.weight;
	}
};

int main(int argc, char *argv[]) {
	int n, m, r;
	scanf("%d%d%d", &n, &m, &r);
	
	//build the g
	int u, v, t;
	memset(firstarc, 0, sizeof(firstarc));
	memset(nextarc, 0, sizeof(nextarc));
	memset(vis, 0, sizeof(vis));
	for(int i=1;i<=m;i++){
		scanf("%d%d%d", &u, &v, &t);
		weight[i] = t;
		nextarc[i] = firstarc[u];
		firstarc[u] = i;
		adj[i] = v;
		weight[i+m] = t;
		nextarc[m+i] = firstarc[v];
		firstarc[v] = m+i;
		adj[m+i] = u;
	}
	
	//MST
	priority_queue<Edge> Q;
	Edge tmp;
	int res = 0;
	int te = firstarc[r];
	vis[r] = true;
	while(te){
		tmp.no = te;
		tmp.weight = weight[te];
		Q.push(tmp);
		te = nextarc[te];
	}
	for(int i=0;i<n-1;i++){
		tmp = Q.top();
		Q.pop();
		int node = adj[tmp.no];
		if(vis[node]){
			i--;
			continue;
		}
		vis[node] = true;
		if(tmp.weight>res)
			res = tmp.weight;
		te = firstarc[node];
		while(te){
			if(!vis[adj[te]]){
				tmp.no = te;
				tmp.weight = weight[te];
				Q.push(tmp);
			}
			te = nextarc[te];
		}
	}
	printf("%d", res);
}