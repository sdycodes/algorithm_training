#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
int n, m;
long long dis[505];
bool vis[505];
struct Edge{
	int u, v, w, t;
	Edge(int u, int v, int w, int t):u(u), v(v), w(w), t(t){}
};

struct Node{
	long long d;
	int u;
	long long p;
	long long l;
	Node(long long d,int u, long long p, long long l):d(d), u(u), p(p), l(l){}
	friend bool operator<(Node a, Node b){
		return a.d > b.d;
	}
};

vector<Edge> edges;
vector<int> g[505];

void Dijkstra(){
	priority_queue<Node> q;
	dis[1] = 0;
	q.push(Node(0, 1, 0, 0));
	while(!q.empty()){
		Node node = q.top();
		q.pop();
		if(vis[node.u])  
			continue;
		vis[node.u] = true;
		for(int i = 0; i < g[node.u].size(); i++){
			Edge e = edges[g[node.u][i]];
			if(e.t==0){ //big
				if(dis[e.v] > node.d + e.w){
					dis[e.v] = node.d + e.w;
					q.push(Node(dis[e.v], e.v, dis[e.v], 0));
				}
			}
			else{ //narrow
				if(dis[e.v] > node.p+(node.l+e.w)*(node.l+e.w) ){
					dis[e.v] = node.p+(node.l+e.w)*(node.l+e.w);
					q.push(Node(dis[e.v], e.v, node.p, e.w + node.l));
				}
			}
		}
	}
}
int main(){
	cin>>n>>m;
	//init
	for(int i = 0; i <= n; i++){
		g[i].clear();
		vis[i] = false;
		dis[i] = INF;
	}
	edges.clear();
	//in
	int u, v, w, t;
	for(int i = 1; i <= m; i++){
		cin>>t>>u>>v>>w;
		edges.push_back(Edge(u, v, w, t));
		g[u].push_back(edges.size() - 1);
		edges.push_back(Edge(v, u, w, t));
		g[v].push_back(edges.size() - 1);
   }
	Dijkstra();
 	cout<<dis[n]<<'\n';
	return 0;
}
