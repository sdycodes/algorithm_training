//
//  lc_tagST_BIT.hpp
//  FAT
//
//  Created by shidingyuan on 2018/8/20.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#ifndef lc_tagST_BIT_h
#define lc_tagST_BIT_h
#include "stdHeader.h"

struct segTreeNode{
    int l, r;   //区间的左右节点索引
    int s, f;   //s是区间和 f是lazy记录
};
void buildSegTree(vector<int> nums, int k, segTreeNode st[], int a, int b, int& tag);
void down(int k, segTreeNode st[]);
void modifyNode(int index, int delta, int k, segTreeNode st[]);
void modifySeg(int a, int b, int delta, int k, segTreeNode st[]);
int searchNode(int index, int k, segTreeNode st[]);
int searchSeg(int a, int b, int k, segTreeNode st[]);
vector<int> fallingSquares(vector<pair<int, int> >& positions);
vector<pair<int, int> > getSkyline(vector<vector<int>>& buildings);
int rectangleArea(vector<vector<int> >& rectangles);
int reversePairs(vector<int>& nums);
vector<Interval> merge(vector<Interval>& intervals);
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval);
bool less_start(const Interval &a, const Interval &b);

#endif /* lc_tagST_BIT_h */
