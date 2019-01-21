//
//  lc_tagTreeRecur.hpp
//  FAT
//
//  Created by shidingyuan on 2018/8/12.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#ifndef lc_tagTreeRecur_h
#define lc_tagTreeRecur_h
#include "stdHeader.h"
TreeNode* createByLayer(vector<string> nums, int start);
TreeNode* createTreefromString(string a);
void showByLayer(TreeNode* root);
TreeNode* pruneTree(TreeNode* root);
int kthSmallest(TreeNode* root, int k);
int calSubtreeSum(TreeNode* root, map<TreeNode*, int>& memo);
vector<int> findFrequentTreeSum(TreeNode* root);
int numTrees(int n);
void putNode(TreeNode* root, int l, int r, int d, vector<vector<string> >& res);
int calDepth(TreeNode* root);
vector<vector<string>> printTree(TreeNode* root);
void calLeafNum(TreeNode* root, vector<int>& sums, int pre);
int sumNumbers(TreeNode* root);
void getLeafValSeq(TreeNode* root, vector<int>& seq);
bool leafSimilar(TreeNode* root1, TreeNode* root2);
void calSearchPath(TreeNode* tmp, TreeNode* p, vector<TreeNode*>& path);
TreeNode* lowestCommonAncestor0(TreeNode* root, TreeNode* p, TreeNode* q);
string tree2str(TreeNode* t);
TreeNode* subtreeWithAllDeepest(TreeNode* root);
void inorderTraverse(TreeNode* root, vector<TreeNode*>& seq);
void recoverTree(TreeNode* root);
string preorder(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& times);
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
string serialize(TreeNode* root);
TreeNode* deserialize(string data);
vector<int> calMaxPath(TreeNode* root, int& res);
int maxPathSum(TreeNode* root);
int countNodes(TreeNode* root);
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
vector<int> calLongestPath(TreeNode* root, int& res);
int longestUnivaluePath(TreeNode* root);
void calElemNum(string formula, int times, map<string, int>& cnt);
string countOfAtoms(string formula);
bool calPartition(vector<int> nums, int set, vector<bool>& visited, int cur, int tar, int start);
bool canPartitionKSubsets(vector<int>& nums, int k);
string makeLargestSpecial(string S);

#endif /* lc_tagTreeRecur_h */
