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

vector<Edge> edges;
vector<int> g[500005];
bool vis[500005];

int main(int argc, char *argv[]) {
	int n, m, r;
	cin>>n>>m>>r;
	//init
	for(int i=0;i<n;i++){
		g[i].clear();
	}
	edges.clear();
	//build the g
	int u, v, w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		edges.push_back(Edge(u,v,w,i));
		g[u].push_back(edges.size()-1);
		edges.push_back(Edge(v,u,w,i+m));
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
		if(tmp.w>res)
			res = tmp.w;
		for(int i=0;i<g[tmp.v].size();i++){
			Edge ne = edges[g[tmp.v][i]];
			if(!vis[ne.v]){
				q.push(ne);
			}
		}
	}
	cout<<res;
}