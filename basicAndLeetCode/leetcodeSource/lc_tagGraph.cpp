//
//  lc_tagGraph.cpp
//  FAT
//
//  Created by shidingyuan on 2018/8/10.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#include "stdHeader.h"
#include "dataStructure.h"
//TODO:Overview
//group1:find union
//684 冗余链接：无向图 并查集应用
//685 冗余链接II：有向图 find-union策略判断是否有环 有向图分成三种情况讨论
//group2：度
//207 课程表： DAG 拓扑序
//310 最小高度树：度性质、求深度的模板、unordered_set的使用（高度一种是传统求深度、一种是度）
//802 找到安全状态：度性质（联系310、207）逆序删除保持sink状态
//group3：图是关系
//399 除法：图的本质关系：实现问题到点、边、路径的映射
//group4：层次、BFS、SSSP
//743 网络传播延时：本质是SSSP、因为最先被影响的点先传递
//785 判断二分图：BFS间隔染色 BFS的层次性
//854 k相似字符串：BFS的试探性和层次性 层次性保证的重要手段就是visited标记、防止不当松弛、保证最优解
//group5:others
//332 重建旅途：欧拉路径模板
//133 克隆图：无意义
//765 情侣牵手：其实是个贪心、和图的相关性设计代数知识比较复杂

//TODO: LC 684. Redundant Connection
//并查集的应用
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int N = (int)edges.size(), i;
    vector<struct unionNode* > nodes(N);
    for(i=1;i<=N;i++)
        nodes[i-1] = createSet(i);
    for(i=0;i<N;i++){
        if(findSet(nodes[edges[i][0]-1])==findSet(nodes[edges[i][1]-1]))
            break;
        else
            uni2sets(nodes[edges[i][0]-1], nodes[edges[i][1]-1]);
    }
    return edges[i];
}

//TODO: LC 685. Redundant Connection II
//并查思想灵活使用
int getRoot(vector<int>& root, int i) {
    return i == root[i] ? i : getRoot(root, root[i]);
}
vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = (int)edges.size();
    vector<int> root(n + 1, 0), first, second;
    for (auto& edge : edges) {
        if (root[edge[1]] == 0) {
            root[edge[1]] = edge[0];
        } else {
            first = {root[edge[1]], edge[1]};
            second = edge;
            edge[1] = 0;
        }
    }
    for (int i = 0; i <= n; ++i) root[i] = i;
    for (auto& edge : edges) {
        if (edge[1] == 0) continue;
        int x = getRoot(root, edge[0]), y = getRoot(root, edge[1]);
        if (x == y) return first.empty() ? edge : first;
        root[x] = y;
    }
    return second;
}

//TODO: LC 207. Course Schedule
//topo序的应用
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> indeg(numCourses, 0);
    vector<vector<bool> > mat(numCourses, vector<bool>(numCourses, false));
    for(int i=0;i<prerequisites.size();i++){
        indeg[prerequisites[i].first]++;
        mat[prerequisites[i].second][prerequisites[i].first] = true;
    }
    vector<bool> visited(numCourses, false);
    queue<int> Q;
    for(int i=0;i<indeg.size();i++)
        if(indeg[i]==0) Q.push(i);
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        visited[node] =true;
        for(int i=0;i<mat[node].size();i++)
            if(mat[node][i]){
                indeg[i]--;
                if(indeg[i]==0)
                    Q.push(i);
            }
    }
    for(int i=0;i<visited.size();i++)
        if(visited[i]==false) return false;
    return true;
}

//TODO: LC 310. Minimum Height Trees
//思路：全遍历TLE 特征为 一层层剥开 最后剩下的1～2个点
//实现：indeg+visited方法过于繁琐 使用unordered_set （遍历方法）
vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
    if(n==1) return {0};    //vector常量
    vector<int> res;
    vector<unordered_set<int>> adj(n);
    queue<int> Q;
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first].insert(edges[i].second);
        adj[edges[i].second].insert(edges[i].first);
    }
    for(int i=0;i<n;i++)
        if(adj[i].size()==1) Q.push(i);
    while(n>2){
        int size = (int)Q.size();
        n -= size;
        for(int i = 0;i<size;i++){
            int t = Q.front();
            Q.pop();
            for(auto a : adj[t]){
                adj[a].erase(t);
                if(adj[a].size()==1)
                    Q.push(a);
            }
        }
    }
    while(!Q.empty()){
        res.push_back(Q.front());
        Q.pop();
    }
    return res;
}
//这个非递归计算层次的方法是模板
int DeepTraverse(vector<int> nodes, vector<pair<int, int> > edges, vector<int> next, vector<bool>& visit, int node){
    visit[node] = true;
    queue<int> Q;
    Q.push(node);
    int res = 0, l=-1, r=0, tag=0;
    while(!Q.empty()){
        int n = Q.front();
        visit[n] = true;
        Q.pop();
        l++;
        for(int e=nodes[n];e!=-1;e=next[e])
            if(!visit[edges[e].second]){
                Q.push(edges[e].second);
                r++;
            }
        if(l==tag){
            tag = r;
            res++;
        }
    }
    return res;
}

//TODO: LC 802. Find Eventual Safe States
//拓扑逆序的又一应用
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    if(graph.size()==0) return {};
    vector<int> res;
    vector<vector<int>> rgraph(graph.size(), vector<int>(0));
    for(int u=0;u<graph.size();u++)
        for(int v=0;v<graph[u].size();v++)
            rgraph[graph[u][v]].push_back(u);
    int j = 0;
    int pre = -1;
    vector<bool> visited(graph.size(), false);
    while(pre!=res.size()){
        for(int i=0;i<graph.size();i++)
            if(graph[i].size()==0&&!visited[i]){
                visited[i] = true;
                res.push_back(i);
            }
        pre = j;
        while(j<res.size()){
            for(int k=0;k<rgraph[res[j]].size();k++)
                graph[rgraph[res[j]][k]].erase(remove(graph[rgraph[res[j]][k]].begin(), graph[rgraph[res[j]][k]].end(), res[j]), graph[rgraph[res[j]][k]].end());
            j++;
        }
    }
    sort(res.begin(), res.end());
    return res;
}

//TODO: LC 399. Evaluate Division
//关键是反向边要加上去
double dfs4val(vector<bool>& evisited, map<string, int> firstedge, vector<int> nextedge, vector<pair<string, string>> equations, vector<double> values2, string node, int edge, string target){
    if(edge!=-1)    evisited[edge] = true;
    if(node==target)    return values2[edge];
    for(int tmp = firstedge[node];tmp!=-1;tmp = nextedge[tmp]){
        double x = -1.0;
        if(!evisited[tmp])
            x = dfs4val(evisited, firstedge, nextedge, equations, values2, equations[tmp].second, tmp, target);
        if(x!=-1)   return (edge==-1)?x:values2[edge]*x;
    }
    return  -1.0;
}
vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    vector<double> res(queries.size());
    map<string, int> firstedge;
    vector<int> nextedge(2*equations.size(), -1);
    vector<double> values2(2*values.size());
    vector<pair<string, string>> equations2(2*equations.size());
    //create graph
    for(int i=0;i<equations.size();i++){
        firstedge[equations[i].first] = -1;
        firstedge[equations[i].second] = -1;
    }
    for(int i=0;i<equations.size();i++){
        nextedge[i] = firstedge[equations[i].first];
        firstedge[equations[i].first] = i;
        nextedge[i+values.size()] = firstedge[equations[i].second];
        firstedge[equations[i].second] = i+(int)values.size();
        values2[i] = values[i];
        values2[i+values.size()] = 1.0/values[i];
        equations2[i] = equations[i];
        equations2[i+values.size()] = {equations[i].second, equations[i].first};
    }
    for(int i=0;i<queries.size();i++){
        if(queries[i].first==queries[i].second){
            if(firstedge.find(queries[i].first)!=firstedge.end())
                res[i] = 1.0;
            else
                res[i] = -1.0;
        }
        else if(firstedge.find(queries[i].first)==firstedge.end()||firstedge.find(queries[i].second)==firstedge.end())
            res[i] = -1.0;
        else{
            vector<bool> evisited(equations.size()*2, false);
            res[i] = dfs4val(evisited, firstedge, nextedge, equations2, values2, queries[i].first, -1, queries[i].second);
        }
    }
    return res;
}

uint32_t reverseBits(uint32_t n) {
    vector<char> bit;
    while(n){
        bit.push_back(n%2);
        n/=2;
    }
    uint32_t res = 0;
    for(int i=(int)bit.size();i<32;i++)
        bit.push_back(0);
    for(int i=(int)bit.size()-1;i>=0;i--){
        res += (int)bit[i]*pow(2, bit.size()-1-i);
    }
    return res;
}

//TODO: LC 743. Network Delay Time
//findmin因为不是优先队列
//需要注意1、取过的不参与选择visited数组的作用
//2、min的初始值很重要 如果是已经出现的某个元素 可能无法被松弛 visited
int nfindmin(vector<int> wakeup, vector<bool> visited){
    int min = INT_MAX, r = 0;
    for(int i=0;i<wakeup.size();i++)
        if(min>=wakeup[i]&&!visited[i]){
            min = wakeup[i];
            r = i;
        }
    return r;
}
int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    int i, node, adje;
    vector<int> nodes(N, -1);
    vector<int> next(times.size(), -1);
    for(i=0;i<times.size();i++){
        next[i] = nodes[times[i][0]-1];
        nodes[times[i][0]-1] = i;
    }
    vector<int> wakeup(N, INT_MAX);
    vector<bool> visited(N, false);
    wakeup[K-1] = 0;
    int visitNum = 0;
    while(visitNum!=N){
        node = nfindmin(wakeup, visited);
        visitNum++;
        visited[node] = true;
        for(adje=nodes[node];adje!=-1;adje=next[adje])
            wakeup[times[adje][1]-1] = min(wakeup[node]+times[adje][2], wakeup[times[adje][1]-1]);
    }
    
    int latest = wakeup[0];
    for(i=0;i<N;i++)
        latest = max(latest, wakeup[i]);
    return latest==INT_MAX?-1:latest;
}

//TODO: LC 785. Is Graph Bipartite?
//使用bfs判断二分图
bool isBipartite(vector<vector<int>>& graph) {
    vector<char> color(graph.size(), 'w');
    queue<int> Q;
    for(int i=0;i<graph.size();i++){
        if(color[i]=='w'){
            color[i] = 'r';
            Q.push(i);
            while(!Q.empty()){
                int tmp = Q.front();
                Q.pop();
                for(auto adj:graph[tmp]){
                    if(color[adj]=='w'){
                        Q.push(adj);
                        color[adj] = color[tmp]=='b'?'r':'b';
                    }
                    else if(color[tmp]==color[adj])
                        return false;
                }
            }
        }
    }
    return true;
}

//TODO: LC 854. K-Similar Strings
int kSimilarity(string A, string B) {
    queue<string> Q;
    map<string, int> times;
    Q.push(A);
    times[A] = 0;
    while(!Q.empty()){
        string tmp = Q.front();
        Q.pop();
        if(tmp==B)  return times[tmp];
        for(int i=0;i<tmp.length();i++){
            if(tmp[i]==B[i]) continue;
            for(int j=i+1;j<tmp.length();j++){
                if(tmp[j]==B[i]){
                    string ntmp = tmp;
                    ntmp[i] = tmp[j];
                    ntmp[j] = tmp[i];
                    if(times.find(ntmp)==times.end()){
                        times[ntmp] = times[tmp]+1;
                        Q.push(ntmp);
                    }
                }
            }
            break;
        }
    }
    return 0;
}


//TODO: LC 332. Reconstruct Itinerary
//计算欧拉路径模板题
bool calEulerPath(map<string, int> nodes, vector<int> next, vector<pair<string, string>> tickets, vector<bool>& visited, int &evisnum, vector<string>& path, int e, string node){
    path.push_back(node);
    if(e!=-1) {
        visited[e] = true;
        evisnum++;
    }
    if(evisnum==tickets.size()) return true;
    for(int tmp=nodes[node];tmp!=-1;tmp = next[tmp])
        if(!visited[tmp])
            if(calEulerPath(nodes, next, tickets, visited, evisnum, path, tmp, tickets[tmp].second))
                return true;
    evisnum--;
    visited[e] = false;
    path.pop_back();
    return false;
}
vector<string> findItinerary(vector<pair<string, string>> tickets){
    map<string, int> nodes;
    for(int i=0;i<tickets.size();i++){
        nodes[tickets[i].first] = -1;
        nodes[tickets[i].second] = -1;
    }
    vector<int> next(tickets.size(), -1);
    for(int i=0;i<tickets.size();i++){
        int tmp = nodes[tickets[i].first], pre = -1;
        while(tmp!=-1&&tickets[i].second>=tickets[tmp].second){
            pre = tmp;
            tmp = next[tmp];
        }
        next[i] = tmp;
        if(pre==-1)
            nodes[tickets[i].first] = i;
        else
            next[pre] = i;
    }
    vector<bool> visited(tickets.size(), false);
    vector<string> path;
    int evisnum = 0;
    calEulerPath(nodes, next, tickets, visited, evisnum, path, -1, "JFK");
    return path;
}

//TODO: LC 133. Clone Graph
//水题 不知道干啥

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    if(node==NULL) return NULL;
    UndirectedGraphNode* res = new UndirectedGraphNode(node->label);
    mp[node] = res;
    queue<UndirectedGraphNode*> Q;
    Q.push(node);
    while(!Q.empty()){
        UndirectedGraphNode* tmp = Q.front();
        Q.pop();
        for(auto adj:tmp->neighbors){
            if(mp.find(adj)==mp.end()){
                UndirectedGraphNode* adj2 = new UndirectedGraphNode(adj->label);
                mp[adj] = adj2;
                Q.push(adj);
            }
            mp[tmp]->neighbors.push_back(mp[adj]);
        }
    }
    return res;
}


//TODO: LC 765. Couples Holding Hands
int minSwapsCouples(vector<int>& row) {
    int k = 0;
    for(int i=0;i<row.size()-2;i++){
        int cp = row[i]^1;
        if(row[i+1]==cp)    i++;
        else{
            for(int j=i+1;j<row.size();j++)
                if(row[j]==cp){
                    int tmp = row[i+1];
                    row[i+1] = row[j];
                    row[j] = tmp;
                    k++;
                    i++;
                    break;
                }
        }
    }
    return k;
}
