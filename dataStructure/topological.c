//
//  main.c
//  topological
//
//  Created by shidingyuan on 2017/12/4.
//  Copyright © 2017年 Shi Dingyuan. All rights reserved.
//
//topological sort
//critical path
//shortest path
#include <stdio.h>
#include <stdlib.h>
#define numsOfLine 8
#define numsOfNode 6
//create a DAG(directed acycline graph)

//every nodes first outline
int begin[numsOfNode] = {0,3,4,6,7,-1};
//lines followed by firstline
int nextline[numsOfLine] = {1,-1,-1,2,5,-1,-1,-1};
//lines' weight
int weight[numsOfLine] = {3,2,2,3,4,3,2,1};
//lines' end
int end[numsOfLine] = {1,2,3,4,3,5,5,5};

//caculate in degree
int* getIndegree(int end[]){
    int i;
    int *indegree;
    indegree = (int *)malloc(sizeof(int)*numsOfNode);
    //pay attention to initialization
    for(i=0;i<numsOfNode;i++)
        indegree[i] = 0;
    for(i=0;i<numsOfLine;i++)
        //if the point is in array end,mains it has a indegree
        indegree[end[i]]++;
    return indegree;
}
//计算入度，直接看end数组即可

//topological sort
int* topolSort(int *indegree, int begin[], int nextline[]){
    int * topolist;
    int visited[numsOfNode] = {0};
    topolist = (int*)malloc(sizeof(int)*numsOfNode);
    int i,j = 0, k;
    for(i=0;i<numsOfNode;i++){
        if(indegree[i]==0&&visited[i]!=1){
            //put into the list
            topolist[j++] = i;
            visited[i] = 1;
            //delete the line change the indegree
            k = begin[i];
            while(k!=-1){
                indegree[end[k]]--;
                k = nextline[k];
            }
            //to restart the loop
            i = -1;
        }
    }
    return topolist;
}
//拓扑排序，visited数组标记访问情况（因为没有做删除这样的破坏性操作，保留了原来的数组） 注意边遍历形式，后面常用

//calculate critical path
//two array 1) earlist start time 2)latest start time
int ve[numsOfNode] = {0};
int vl[numsOfNode] = {0};
//important if getting the begin is hard,we can cal it ahead of getting it;
void getve(int begin[],int end[], int weight[], int topolist[]){
    int i, k;
    extern int ve[];
    for(i=0;i<numsOfNode-1;i++){
        k = begin[topolist[i]];
        while(k!=-1){
            //we calculate the next node time before we get to it
            //because it's hard to return to get pre node's ve
            if(ve[end[k]]<ve[topolist[i]]+weight[k])
                ve[end[k]] = ve[topolist[i]]+weight[k];
            k = nextline[k];
        }
    }
}
//计算ve（最早开始时间）初始化为0，以便求最大值，这个过程其实可以在排序时实现
//重点：到了一个点找他的前驱很麻烦，而计算ve恰好需要前驱，这里转变思路，在前面计算其后继的ve

void getvl(int begin[],int end[], int weight[], int* topolist){
    extern int vl[];
    //initialize vk
    int i,k;
    for(i=0;i<numsOfNode;i++)
        vl[i] = ve[topolist[numsOfNode-1]];
    for(i=numsOfNode-2;i>=0;i--){
        k = begin[topolist[i]];
        while(k!=-1){
            if(vl[topolist[i]]>vl[end[k]]-weight[k])
                vl[topolist[i]] = vl[end[k]]-weight[k];
            k = nextline[k];
        }
    }
}
//初始化为最大的数字，也就是topolist末尾的ve，便于找最小值
//vl的求解比ve简单，因为需要的是后继的值，这个数据结构比较适合顺着找

//output critical activity
void outputCrticalActivity(int ve[], int vl[], int begin[], int *topolist){
    int k;
    printf("the critical activity is:\n");
    k = begin[topolist[0]];
    while(k!=-1){
        if(ve[end[k]]==vl[end[k]]){
            printf("%d ", k);
            k = begin[end[k]];
        }
        else
            k = nextline[k];
    }
}
//输出，注意这里只要一个循环，因为关键路径可以一条路走到底
//所以一旦找对了，可以直接跳到这个点所连的第一条边

//shortest path
int g[numsOfNode][numsOfNode]= {500,500,10,500,30,100,500,500,5,500,500,500,500,500,500,50,500,500,500,500,500,500,500,10,500,500,500,20,500,60,500,500,500,500,500,500};
void shortestPath(int** g, int v0){
    int D[numsOfNode] = {0};
    int path[numsOfNode][numsOfNode];
    int visited[numsOfNode] ={0};
    int i, j,k = 0,tag,t=0, min = 500;
    for(i=1;i<numsOfNode;i++){
        D[i] = g[v0][i];
    }
    for(i=1;i<numsOfNode;i++){
        min = 500;
        for(j=0;j<numsOfNode;j++){
            if(min>D[j]&&visited[j]!=1){
                min = D[j];
                tag = j;
            }
        }
        visited[tag] = 1;
        for(j=0;j<numsOfNode;j++)
            if(visited[j]!=1&&min+g[tag][j]<D[j]){
                D[j] = min+g[tag][j];
                //复制之前走的路
                for(k=0;k<numsOfNode;k++)
                    path[j][k] = path[tag][k];
                path[j][j] = 1;
            }
        }
}
int main(int argc, const char * argv[]) {
    int * indegree,*topolist;
    int i;
    indegree = (int*)malloc(sizeof(int)*numsOfNode);
    topolist = (int*)malloc(sizeof(int)*numsOfNode);
    indegree = getIndegree(end);
    topolist = topolSort(indegree, begin, nextline);
    for(i=0;i<numsOfNode;i++)
        printf("%d ",topolist[i]);
    printf("\n");
    getve(begin, end, weight, topolist);
    getvl(begin, end, weight, topolist);
    outputCrticalActivity(ve, vl, begin, topolist);
    return 0;
}
