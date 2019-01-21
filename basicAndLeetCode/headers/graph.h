//
//  graph.h
//  FAT
//
//  Created by shidingyuan on 2018/7/31.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#ifndef graph_h
#define graph_h
#include "stdHeader.h"
//definition of graph data structure
//Non-weight Graph
#define maxNode 100
#define maxEdge 1000

struct NG{
    int nodeNum;
    int edgeNum;
    int nodes[maxNode];
    int nextedge[maxEdge];
    int edgeadj1[maxEdge];
    int edgeadj2[maxEdge];
    int w[maxNode][maxNode];
};


//basic operation on graph
void addEdge(struct NG &graph,int edge, int node1, int node2, char dir, char weight, int edgeweight[], int val);
void deleteEdge(struct NG &graph,int edge, int dir);
void addNode(struct NG &graph, int node, int edges[], int adj[], int size, char dir, char weight, int edgeweight[], int val);
void deleteNode(struct NG &graph, int node);
void createG(struct NG &graph, char weight, int edgeweight[]);
void showG(struct NG graph, int edgeweight[], char weight, char dir);

//traverse on graph
void dfs(struct NG graph,int node,int d[],int f[],int pre[], char color[],int &time);
void dfsVisit(struct NG graph, int d[],int f[], int pre[], char color[]);
void bfs(struct NG graph, int d[], char color[], int pre[], int node);
void bfsVisit(struct NG graph, int d[], char color[], int pre[]);
void showRes(struct NG g,char color[],int d[],int f[],int pre[],char o);

//calculate SCC
void reverseG(struct NG &graph);
void dfs4scc(struct NG graph, int node, char color[], int L[], int &tag);
void dfsV4scc(struct NG graph, int L[]);
void dfs4sccRec(struct NG graph,int node,char color[],vector<int> &scc);
void calSCC(struct NG graph, vector<vector<int> > &sccs);

//calculate MST Kruscal algorithm
struct edge{
    int id;
    int weight;
    int adj1;
    int adj2;
};
int Kpartition(struct edge *edges, int begin, int end);
void Kquicksort(struct edge *edges, int begin, int end);
vector<int> kruscal(struct NG graph, int edgeweight[]);

//single source shortest path (SSSP)
void Dij(struct NG graph,int edgeweight[],int pre[],int dist[],int src);

//calculate max-flow
int dfs4mf(struct NG gr, int node, int wr[], char color[], int t, vector<int> &path);
int dfsV4mf(struct NG gr, int wr[], int s, int t, vector<int> &path);
int maxflow(struct NG g, int edgeweight[], int s, int t, int f[]);
#endif /* graph_h */


//test
/*
 struct NG g;
 //Weighted Graph
 int edgeweight[maxEdge];
 //check dfs  bfs
 createG(g, 'w', edgeweight);
 addEdge(g, 0, 0, 1, 'u', 'n', 0, 0);
 addEdge(g, 1, 0, 4, 'u', 'n', 0, 0);
 addEdge(g, 2, 0, 6, 'u', 'n', 0, 0);
 addEdge(g, 3, 4, 6, 'u', 'n', 0, 0);
 addEdge(g, 4, 1, 2, 'u', 'n', 0, 0);
 addEdge(g, 5, 1, 3, 'u', 'n', 0, 0);
 addEdge(g, 6, 4, 5, 'u', 'n', 0, 0);
 addEdge(g, 7, 4, 7, 'u', 'n', 0, 0);
 addEdge(g, 8, 3, 7, 'u', 'n', 0, 0);
 addEdge(g, 9, 2, 5, 'u', 'n', 0, 0);
 showG(g, 0, 'n', 'u');
 char color[8];
 int d[8], f[8];
 int pre[8];
 dfsVisit(g, d, f, pre, color);
 showRes(g, color, d, f, pre, 'd');
 bfsVisit(g, d, color, pre);
 showRes(g, color, d, f, pre, 'b');
 */
/*
 //check cal SCC
 createG(g, 'u', edgeweight);
 addEdge(g, 0, 0, 2, 'd', 'n', 0, 0);
 addEdge(g, 1, 2, 1, 'd', 'n', 0, 0);
 addEdge(g, 2, 1, 0, 'd', 'n', 0, 0);
 addEdge(g, 3, 0, 5, 'd', 'n', 0, 0);
 addEdge(g, 4, 3, 0, 'd', 'n', 0, 0);
 addEdge(g, 5, 5, 3, 'd', 'n', 0, 0);
 addEdge(g, 6, 3, 6, 'd', 'n', 0, 0);
 addEdge(g, 7, 6, 5, 'd', 'n', 0, 0);
 addEdge(g, 8, 4, 3, 'd', 'n', 0, 0);
 addEdge(g, 9, 4, 6, 'd', 'n', 0, 0);
 addEdge(g, 10, 7, 6, 'd', 'n', 0, 0);
 addEdge(g, 11, 7, 8, 'd', 'n', 0, 0);
 addEdge(g, 12, 8, 7, 'd', 'n', 0, 0);
 addEdge(g, 13, 4, 4, 'd', 'n', 0, 0);
 addEdge(g, 14, 3, 9, 'd', 'n', 0, 0);
 addEdge(g, 15, 5, 10, 'd', 'n', 0, 0);
 addEdge(g, 16, 10, 9, 'd', 'n', 0, 0);
 addEdge(g, 17, 9, 11, 'd', 'n', 0, 0);
 addEdge(g, 18, 11, 10, 'd', 'n', 0, 0);
 addEdge(g, 19, 4, 8, 'd', 'n', 0, 0);
 vector< vector<int> > sccs;
 calSCC(g, sccs);
 cout<<'\n';
 for(int i=0;i<sccs.size();i++){
 for(int j=0;j<sccs[i].size();j++)
 cout<<sccs[i][j]<<' ';
 cout<<'\n';
 }
 */
/*
 //check cal MST
 createG(g, 'w', edgeweight);
 addEdge(g, 0, 0, 1, 'u', 'w', edgeweight, 4);
 addEdge(g, 1, 0, 2, 'u', 'w', edgeweight, 8);
 addEdge(g, 2, 1, 2, 'u', 'w', edgeweight, 9);
 addEdge(g, 3, 1, 4, 'u', 'w', edgeweight, 10);
 addEdge(g, 4, 1, 3, 'u', 'w', edgeweight, 8);
 addEdge(g, 5, 2, 3, 'u', 'w', edgeweight, 2);
 addEdge(g, 6, 2, 5, 'u', 'w', edgeweight, 1);
 addEdge(g, 7, 3, 4, 'u', 'w', edgeweight, 7);
 addEdge(g, 8, 3, 5, 'u', 'w', edgeweight, 2);
 addEdge(g, 9, 4, 5, 'u', 'w', edgeweight, 5);
 addEdge(g, 10, 4, 6, 'u', 'w', edgeweight, 6);
 addEdge(g, 11, 5, 6, 'u', 'w', edgeweight, 2);
 showG(g, edgeweight, 'w', 'u');
 vector<int> treeedges = kruscal(g, edgeweight);
 for(int i=0;i<treeedges.size();i++)
 cout<<treeedges[i]<<' ';
 cout<<'\n';
 */

/*
 //check cal SSSP
 createG(g, 'w', edgeweight);
 addEdge(g, 0, 0, 2, 'd', 'w', edgeweight, 7);
 addEdge(g, 1, 0, 1, 'd', 'w', edgeweight, 2);
 addEdge(g, 2, 2, 1, 'd', 'w', edgeweight, 2);
 addEdge(g, 3, 1, 2, 'd', 'w', edgeweight, 3);
 addEdge(g, 4, 2, 3, 'd', 'w', edgeweight, 1);
 addEdge(g, 5, 1, 3, 'd', 'w', edgeweight, 8);
 addEdge(g, 6, 1, 4, 'd', 'w', edgeweight, 5);
 addEdge(g, 7, 3, 4, 'd', 'w', edgeweight, 4);
 addEdge(g, 8, 4, 3, 'd', 'w', edgeweight, 5);
 int pre[5], dist[5];
 Dij(g, edgeweight, pre, dist, 0);
 for(int i=0;i<g.nodeNum;i++)
 cout<<pre[i]<<' ';
 cout<<'\n';
 for(int i=0;i<g.nodeNum;i++)
 cout<<dist[i]<<' ';
 cout<<'\n';
 */
/*
 //check maxflow
 createG(g, 'w', edgeweight);
 addEdge(g, 0, 0, 1, 'd', 'w', edgeweight, 10);
 addEdge(g, 1, 0, 2, 'd', 'w', edgeweight, 10);
 addEdge(g, 2, 1, 2, 'd', 'w', edgeweight, 2);
 addEdge(g, 3, 1, 3, 'd', 'w', edgeweight, 4);
 addEdge(g, 4, 1, 4, 'd', 'w', edgeweight, 8);
 addEdge(g, 5, 2, 4, 'd', 'w', edgeweight, 9);
 addEdge(g, 6, 4, 3, 'd', 'w', edgeweight, 6);
 addEdge(g, 7, 3, 5, 'd', 'w', edgeweight, 10);
 addEdge(g, 8, 4, 5, 'd', 'w', edgeweight, 10);
 int f[9];
 int flow = maxflow(g, edgeweight, 0, 5, f);
 cout<<"maxflow: "<<flow<<'\n';
 for(int i=0;i<9;i++)
 cout<<f[i]<<' ';
 */
