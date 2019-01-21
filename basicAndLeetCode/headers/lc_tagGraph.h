//
//  lc_tagGraph.h
//  FAT
//
//  Created by shidingyuan on 2018/8/10.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#ifndef lc_tagGraph_h
#define lc_tagGraph_h

#include "stdHeader.h"
vector<int> findRedundantConnection(vector<vector<int>>& edges);
int getRoot(vector<int>& root, int i);
vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges);
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges);
int calDepth(vector<int> nodes, vector<pair<int, int> > edges, vector<int> next, vector<bool>& visit, int node);
vector<int> eventualSafeNodes(vector<vector<int>>& graph);
double dfs4val(vector<bool>& evisited, map<string, int> firstedge, vector<int> nextedge, vector<pair<string, string>> equations, vector<double> values2, string node, int edge, string target);
vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries);
uint32_t reverseBits(uint32_t n);
int nfindmin(vector<int> wakeup, vector<bool> visited);
int networkDelayTime(vector<vector<int>>& times, int N, int K);
bool isBipartite(vector<vector<int>>& graph);
int kSimilarity(string A, string B);
bool calEulerPath(map<string, int> nodes, vector<int> next, vector<pair<string, string>> tickets, vector<bool>& visited, int &evisnum, vector<string>& path, int e, string node);
vector<string> findItinerary(vector<pair<string, string>> tickets);
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
int minSwapsCouples(vector<int>& row);

#endif /* lc_tagGraph_h */
