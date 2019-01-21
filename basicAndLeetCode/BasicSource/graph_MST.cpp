//
//  graph_MST.cpp
//  FAT
//
//  Created by shidingyuan on 2018/7/31.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "graph.h"
#include "dataStructure.h"

int Kpartition(struct edge *edges, int begin, int end){
    int i = begin, j = end, tmp;
    int r = edges[i].weight;
    while(i!=j){
        while(edges[j].weight>=r && i<j)
            j--;
        while(edges[i].weight<=r && i<j)
            i++;
        swap(edges[i].weight, edges[j].weight)
        swap(edges[i].id, edges[j].id)
        swap(edges[i].adj1, edges[j].adj1)
        swap(edges[i].adj2, edges[j].adj2)
    }
    swap(edges[i].weight, edges[begin].weight)
    swap(edges[i].id, edges[begin].id)
    swap(edges[i].adj1, edges[begin].adj1)
    swap(edges[i].adj2, edges[begin].adj2)
    return i;
}
void Kquicksort(struct edge *edges, int begin, int end){
    if(begin<end){
        int mid = Kpartition(edges, begin, end);
        Kquicksort(edges, begin, mid-1);
        Kquicksort(edges, mid+1, end);
    }
}
vector<int> kruscal(struct NG graph, int edgeweight[]){
    struct edge *edges;
    edges = (struct edge*)malloc(sizeof(struct edge)*(graph.edgeNum>>1));
    int i;
    //复制下来再处理  避免破坏原来的记录
    for(i=0;i<(graph.edgeNum>>1);i++){
        edges[i].weight = edgeweight[i];
        edges[i].adj1 = graph.edgeadj1[i];
        edges[i].adj2 = graph.edgeadj2[i];
        edges[i].id = i;
    }
    Kquicksort(edges, 0, (graph.edgeNum>>1)-1);
    for(i=0;i<(graph.edgeNum>>1)-1;i++)
        cout<<edges[i].id
        <<' '<<edges[i].adj1<<' '<<edges[i].adj2
        <<' '<<edges[i].weight<<'\n';
    vector<int> treeedges;
    struct unionNode** nodes;
    nodes = (struct unionNode**)malloc(sizeof(struct unionNode*)*graph.nodeNum);
    for(i=0;i<graph.nodeNum;i++)
        nodes[i] = createSet(i);
    int node1, node2;
    for(i=0;i<(graph.edgeNum>>1);i++){
        node1 = edges[i].adj1;
        node2 = edges[i].adj2;
        if(findSet(nodes[node1])!=findSet(nodes[node2])){
            treeedges.push_back(edges[i].id);
            uni2sets(nodes[node1], nodes[node2]);
        }
    }
    return treeedges;
}
