//
//  graph_SSSP.cpp
//  FAT
//
//  Created by shidingyuan on 2018/7/31.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "graph.h"
#include "dataStructure.h"

void Dij(struct NG graph,int edgeweight[],int pre[],int dist[],int src){
    int i, node, adje, adjn;
    for(i=0;i<graph.nodeNum;i++){
        dist[i] = INT_MAX;
        pre[i] = -1;
    }
    dist[src] = 0;
    struct pqueue* Q = createQ(maxNode);
    for(i=0;i<graph.nodeNum;i++)
        insertQ(dist[i], i, Q);
    while(Q->eleNum!=0){
        node = extractQ(Q)[1];
        for(adje=graph.nodes[node];adje!=-1;adje=graph.nextedge[adje]){
            adjn = graph.edgeadj2[adje];
            if(dist[adjn]>dist[node]+graph.w[node][adjn]){
                dist[adjn] = dist[node]+graph.w[node][adjn];
                decVal(Q, dist[adjn], adjn);
                pre[adjn] = node;
            }
        }
    }
    free(Q);
}
