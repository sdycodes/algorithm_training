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
	int u, v, w, n;
	Edge(int u, int v, int w, int n):u(u), v(v), w(w), n(n){}
};

struct Node{
	long long d;
	int u;
	Node(long long d,int u):d(d),u(u) {}
	friend bool operator<(Node a, Node b){
		return a.d > b.d;
	}
};

vector<Edge> edges;
vector<int> g[505];
int pre[505];
void Dijkstra(){
	priority_queue<Node> q;
	dis[1] = 0;
	q.push(Node(0, 1));
	while(!q.empty()){
		Node n = q.top();
		q.pop();
		if(vis[n.u])  
			continue;
		vis[n.u] = true;
		for(int i = 0; i < g[n.u].size(); i++){
			Edge e = edges[g[n.u][i]];
			if(dis[e.v] > n.d + e.w){
				dis[e.v] = n.d + e.w;
				pre[e.v] = e.n;
				q.push(Node(dis[e.v], e.v));
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
		edges.push_back(Edge(u, v, w, edges.size()));
		g[u].push_back(edges.size() - 1);
		edges.push_back(Edge(v, u, w, edges.size()));
		g[v].push_back(edges.size() - 1);
   }	  
	Dijkstra();
 	cout<<dis[n]<<'\n';
	cout<<n<<" ";
	for(int x=pre[n];x!=0;x=pre[edges[x].u]){
		cout<<edges[x].u<<" ";
	}
	cout<<"1";
	return 0;
}
