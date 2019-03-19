#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct Edge{
	int u, v;
	Edge(int u, int v):u(u), v(v){}
};
vector<Edge> edges;
vector<int> g[1005];
vector<int> rg[1005];
int N, M;
int vis[1005];
bool canReach[1005][1005];

void dfs(vector<int> g[], int cur, int src){
	vis[cur] = true;
	for(int i=0;i<g[cur].size();i++){
		int adjn = edges[ g[cur][i] ].v;
		if(!vis[adjn])
			dfs(g, adjn, src);
	}
	canReach[cur][src] = true;
}
int main(int argc, char *argv[]) {
	cin>>N>>M;
	int u, v;
	memset(canReach, 0, sizeof(canReach));
	for(int i=1;i<=M;i++){
		cin>>u>>v;
		edges.push_back(Edge(u, v));
		g[u].push_back(edges.size()-1);
		edges.push_back(Edge(v, u));
		rg[v].push_back(edges.size()-1);
	}
	for(int i=1;i<=N;i++){
		memset(vis, 0, sizeof(vis));
		dfs(g, i, i);
	}
	for(int i=1;i<=N;i++){
		memset(vis, 0, sizeof(vis));
		dfs(rg, i, i);
	}
	int res = 0;
	for(int i=1;i<=N;i++){
		int j;
		for(j=1;j<=N;j++){
			if(!canReach[i][j])
				break;
		}
		if(j==N+1) res++;
	}
	cout<<res;
}