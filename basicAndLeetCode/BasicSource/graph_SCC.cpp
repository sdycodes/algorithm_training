//
//  graph_SCC.cpp
//  FAT
//
//  Created by shidingyuan on 2018/7/31.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "graph.h"

void reverseG(struct NG &graph){
    int i, node1, node2;
    for(i=0;i<graph.edgeNum;i++){
        node1 = graph.edgeadj1[i];
        node2 = graph.edgeadj1[i];
        deleteEdge(graph, i, 'd');
        addEdge(graph, i, node2, node1, 'd', 'n', 0, 0);
    }
}
void dfs4scc(struct NG graph, int node, char color[], int L[], int &tag){
    color[node] = 'g';
    int adje;
    int adjn;
    for(adje=graph.nodes[node];adje!=-1;adje = graph.nextedge[adje]){
        adjn = graph.edgeadj2[adje];
        if(color[adjn]=='w'){
            dfs4scc(graph, adjn, color, L, tag);
        }
    }
    color[node] = 'b';
    L[tag++] = node;
}
void dfsV4scc(struct NG graph, int L[]){
    int i, tag = 0;
    char *color = (char*)malloc(sizeof(char)*graph.nodeNum);
    for(i=0;i<graph.nodeNum;i++)
        color[i] = 'w';
    for(i=0;i<graph.nodeNum;i++){
        if(color[i]=='w')
            dfs4scc(graph, i, color, L, tag);
    }
}
void dfs4sccRec(struct NG graph,int node,char color[],vector<int> &scc){
    color[node] = 'g';
    scc.push_back(node);
    int adje;
    int adjn;
    for(adje=graph.nodes[node];adje!=-1;adje = graph.nextedge[adje]){
        adjn = graph.edgeadj2[adje];
        if(color[adjn]=='w')
            dfs4sccRec(graph, adjn, color, scc);
    }
    color[node] = 'b';
}
void calSCC(struct NG graph, vector<vector<int> > &sccs){
    struct NG dup;
    createG(dup, 'n', 0);
    int i;
    for(i=0;i<graph.edgeNum;i++)
        addEdge(dup,i,graph.edgeadj2[i],graph.edgeadj1[i], 'd', 'u', 0, 0);
    int* L = (int*)malloc(sizeof(int)*graph.nodeNum);
    //showG(dup, 0, 'n', 'd');
    dfsV4scc(dup, L);
    int tmp;
    for(i=0;i<(graph.nodeNum-1)>>1;i++){
        tmp = L[i];
        L[i] = L[graph.nodeNum-i-1];
        L[graph.nodeNum-i-1] = tmp;
    }
    //--------------------
    for(i=0;i<graph.nodeNum;i++)
        cout<<L[i]<<' ';
    //dfs on origin graph
    char *color = (char*)malloc(sizeof(char)*graph.nodeNum);
    for(i=0;i<graph.nodeNum;i++)
        color[i] = 'w';
    for(i=0;i<graph.nodeNum;i++){
        if(color[L[i]]=='w'){
            vector<int> sinkSCC;
            dfs4sccRec(graph, L[i], color, sinkSCC);
            sccs.push_back(sinkSCC);
        }
    }
}
