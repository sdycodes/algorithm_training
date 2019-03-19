#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Edge{
	int u, v, w, n;
	Edge(int u, int v, int w, int n):u(u), v(v), w(w), n(n){}
	friend bool operator<(Edge a, Edge b){
		return a.w > b.w;
	}
};
int max(int a, int b){
	return a>b?a:b;
}
vector<Edge> edges;
vector<int> g[100005];
bool vis[100005];
int pre[100005];
int main(int argc, char *argv[]) {
	int n, m, r;
	cin>>n>>m;
	r = 1;
	//init
	memset(vis, 0, sizeof(vis));
	memset(pre, 0, sizeof(pre));
	for(int i=0;i<n;i++){
		g[i].clear();
	}
	edges.clear();
	//build the g
	int u, v, w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		edges.push_back(Edge(u,v,w,edges.size()));
		g[u].push_back(edges.size()-1);
		edges.push_back(Edge(v,u,w,edges.size()));
		g[v].push_back(edges.size()-1);
	}
	//MST
	priority_queue<Edge> q;
	int res = 0;
	vis[r] = true;
	for(int i=0;i<g[r].size();i++){
		Edge e = edges[g[r][i]];
		q.push(e);
	}
	for(int i=0;i<n-1;i++){
		Edge tmp = q.top();
		q.pop();
		if(vis[tmp.v]){
			i--;
			continue;
		}
		vis[tmp.v] = true;
		pre[tmp.v] = tmp.n;
		for(int i=0;i<g[tmp.v].size();i++){
			Edge ne = edges[g[tmp.v][i]];
			if(!vis[ne.v]){
				q.push(ne);
			}
		}
	}
//	cout<<"---------\n";
//	for(int i=1;i<=n;i++){
//		cout<<i<<":"<<pre[i]<<" "<<edges[pre[i]].u<<" "<<edges[pre[i]].v<<"\n";
//	}
	for(int x=pre[n];x!=0;x=pre[edges[x].u]){
		res = max(res, edges[x].w);
	}
	cout<<res;
}