//
//  graph_maxflow.cpp
//  FAT
//
//  Created by shidingyuan on 2018/7/31.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "graph.h"


int dfs4mf(struct NG gr, int node, int wr[], char color[], int t, vector<int> &path){
    color[node] = 'g';
    if(node==t) return 1;
    int adje, x=0;
    for(adje=gr.nodes[node];adje!=-1;adje=gr.nextedge[adje]){
        if(wr[adje]!=0&&color[gr.edgeadj2[adje]]=='w')
            x = dfs4mf(gr, gr.edgeadj2[adje], wr, color, t, path);
        if(x==1){
            path.push_back(adje);
            return 1;
        }
    }
    return 0;
}
int dfsV4mf(struct NG gr, int wr[], int s, int t, vector<int> &path){
    char* color = (char*)malloc(sizeof(char)*gr.nodeNum);
    int i;
    for(i=0;i<gr.nodeNum;i++){
        color[i] = 'w';
    }
    return dfs4mf(gr, s, wr, color, t, path);
}
int maxflow(struct NG g, int edgeweight[], int s, int t, int f[]){
    int flow = 0, i;
    int wr[maxEdge];
    struct NG gr;
    gr.nodeNum = g.nodeNum;
    gr.edgeNum = g.edgeNum;
    for(i=0;i<g.edgeNum;i++){
        gr.edgeadj1[i] = g.edgeadj1[i];
        gr.edgeadj2[i] = g.edgeadj2[i];
        gr.nextedge[i] = g.nextedge[i];
        wr[i] = edgeweight[i];
    }
    for(i=0;i<g.nodeNum;i++)
        gr.nodes[i] = g.nodes[i];
    for(i=0;i<g.edgeNum;i++)
        addEdge(gr, i+100, g.edgeadj2[i], g.edgeadj1[i], 'd', 'w', edgeweight, 0);
    int bottle, x = -1;
    vector<int> path;
    while(1){
        bottle = INT_MAX;
        path.clear();
        x = dfsV4mf(gr, wr, s, t, path);
        if(x==0) break;
        for(i=0;i<path.size();i++)
            if(bottle>wr[path[i]])
                bottle = wr[path[i]];
        flow += bottle;
        for(i=0;i<path.size();i++){
            wr[path[i]] -= bottle;
            wr[path[i]+100] += bottle;
        }
    }
    for(i=0;i<g.edgeNum;i++)
        f[i] = wr[i+100];
    return flow;
}
