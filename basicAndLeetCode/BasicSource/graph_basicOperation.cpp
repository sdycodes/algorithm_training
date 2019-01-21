//
//  graph_basicOperation.cpp
//  FAT
//
//  Created by shidingyuan on 2018/7/31.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "graph.h"

void addEdge(struct NG &graph,int edge, int node1, int node2, char dir, char weight, int edgeweight[], int val){
    graph.edgeNum++;
    graph.w[node1][node2] = (weight=='w'?val:1);
    if(graph.nodes[node1]==-2){
        graph.nodeNum++;
        graph.nodes[node1] = -1;
    }
    if(graph.nodes[node2]==-2){
        graph.nodeNum++;
        graph.nodes[node2] = -1;
    }
    graph.nextedge[edge] = graph.nodes[node1];
    graph.nodes[node1] = edge;
    graph.edgeadj1[edge] = node1;
    graph.edgeadj2[edge] = node2;
    if(weight=='w')
        edgeweight[edge] = val;
    if(dir!='d')
        addEdge(graph, edge+100, node2, node1,'d',weight,edgeweight,val);
}

void deleteEdge(struct NG &graph,int edge, int dir){
    graph.edgeNum--;
    int node1 = graph.edgeadj1[edge];
    int pre = -1, tmp = graph.nodes[node1];
    while(tmp!=edge){
        pre = tmp;
        tmp = graph.nextedge[tmp];
    }
    if(pre==-1)
        graph.nodes[node1] = graph.nextedge[tmp];
    else
        graph.nextedge[tmp] = graph.nextedge[pre];
    if(dir==0)
        deleteEdge(graph, edge+100, 1);
}

void addNode(struct NG &graph, int node, int edges[], int adj[], int size, char dir, char weight, int edgeweight[], int val){
    if(size==0){
        graph.nodeNum++;
        graph.nodes[node] = -1;
        return;
    }
    int i;
    for(i=0;i<size;i++)
        addEdge(graph, edges[i],node,adj[i],dir,weight,edgeweight,val);
}
void deleteNode(struct NG &graph, int node){
    graph.nodeNum--;
    graph.nodes[node] = -2;
}

void createG(struct NG &graph, char weight, int edgeweight[]){
    graph.nodeNum = 0;
    graph.edgeNum = 0;
    int i, j;
    for(i=0;i<maxNode;i++)
        graph.nodes[i] = -2;
    for(i=0;i<maxEdge;i++)
        graph.nextedge[i] = -1;
    if(weight=='w'){
        for(i=0;i<maxEdge;i++)
            edgeweight[i] = -1;
    }
    for(i=0;i<maxNode;i++)
        for(j=0;j<maxNode;j++)
            graph.w[i][j] = INT_MAX;
}


void showG(struct NG graph, int edgeweight[], char weight, char dir){
    cout<<(weight=='w'?"weight graph:":"non-weighted graph")<<'\n';
    cout<<"node nums: "<<graph.nodeNum<<'\n';
    cout<<"nodes: ";
    int i;
    for(i=0;i<graph.nodeNum;i++)
        if(graph.nodes[i]!=-2)
            cout<<i<<' ';
    cout<<'\n';
    cout<<"edge nums: "<<graph.edgeNum<<'\n';
    cout<<"edges: \n";
    if(weight=='w'){
        for(i=0;i<(graph.edgeNum>>(dir=='d'?0:1));i++)
            cout<<'('<<graph.edgeadj1[i]<<','<<graph.edgeadj2[i]<<','
            <<edgeweight[i]<<')'<<' ';
        if(dir=='u'){
            cout<<"\nassist edges: \n";
            for(i=100;i<(graph.edgeNum>>1)+100;i++)
                cout<<'('<<graph.edgeadj1[i]<<','<<graph.edgeadj2[i]<<','
                <<edgeweight[i]<<')'<<' ';
            cout<<'\n';
        }
    }
    else{
        for(i=0;i<(graph.edgeNum>>(dir=='d'?0:1));i++)
            cout<<'('<<graph.edgeadj1[i]<<','<<graph.edgeadj2[i]<<')'<<' ';
        if(dir=='u'){
            cout<<"\nassist edges: \n";
            for(i=100;i<(graph.edgeNum>>1)+100;i++)
                cout<<'('<<graph.edgeadj1[i]<<','
                <<graph.edgeadj2[i]<<')'<<' ';
            cout<<'\n';
        }
    }
}
