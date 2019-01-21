//
//  graph_traverse.cpp
//  FAT
//
//  Created by shidingyuan on 2018/7/31.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "graph.h"

void dfs(struct NG graph,int node,int d[],int f[],int pre[], char color[],int &time){
    color[node] = 'g';
    d[node] = time++;
    int adje;
    int adjn;
    for(adje=graph.nodes[node];adje!=-1;adje = graph.nextedge[adje]){
        adjn = graph.edgeadj2[adje];
        if(color[adjn]=='w'){
            pre[adjn] = node;
            dfs(graph, adjn, d, f, pre, color, time);
        }
    }
    color[node] = 'b';
    f[node] = time++;
}
void dfsVisit(struct NG graph, int d[],int f[], int pre[], char color[]){
    int i, time = 0;
    for(i=0;i<graph.nodeNum;i++){
        color[i] = 'w';
        d[i] = -1;
        f[i] = -1;
        pre[i] = -1;
    }
    for(i=0;i<graph.nodeNum;i++){
        if(color[i]=='w')
            dfs(graph, i, d, f, pre, color, time);
    }
}

void bfs(struct NG graph, int d[], char color[], int pre[], int node){
    int fifo[maxNode], head = 0, rear = 0;
    fifo[rear++] = node;
    int adje, adjn;
    while(head!=rear){
        node = fifo[head++];
        color[node] = 'b';
        for(adje=graph.nodes[node];adje!=-1;adje=graph.nextedge[adje]){
            adjn = graph.edgeadj2[adje];
            if(color[adjn]=='w'){
                color[adjn] = 'g';  //caution: 注意更新颜色的时机
                fifo[rear++] = adjn;
                pre[adjn] = node;
                d[adjn] = d[node]+1;
            }
        }
    }
}

void bfsVisit(struct NG graph, int d[], char color[], int pre[]){
    int i;
    for(i=0;i<graph.nodeNum;i++){
        color[i] = 'w';
        d[i] = 0;
        pre[i] = -1;
    }
    for(i=0;i<graph.nodeNum;i++)
        if(color[i]=='w'){
            d[i] = 0;
            bfs(graph, d, color, pre, i);
        }
}

void showRes(struct NG g,char color[],int d[],int f[],int pre[],char o){
    int i;
    cout<<"result of "<<(o=='d'?"dfs":"bfs")<<'\n';
    cout<<"color: \n";
    for(i=0;i<g.nodeNum;i++)
        cout<<color[i]<<' ';
    cout<<"\nd: \n";
    for(i=0;i<g.nodeNum;i++)
        cout<<d[i]<<' ';
    if(o=='d'){
        cout<<"\nf: \n";
        for(i=0;i<g.nodeNum;i++)
            cout<<f[i]<<' ';
    }
    cout<<"\npre: \n";
    for(i=0;i<g.nodeNum;i++)
        cout<<pre[i]<<' ';
    cout<<'\n';
}

