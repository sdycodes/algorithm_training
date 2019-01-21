//
//  lc_tagDC_.h
//  FAT
//
//  Created by shidingyuan on 2018/8/13.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#ifndef lc_tagDC_h
#define lc_tagDC_h

#include "stdHeader.h"
vector<int> diffWaysToCompute(string input);
vector<int> countSmaller(vector<int>& nums);
int countNums(vector<long>& sums, int lower, int upper, int begin, int end);
int countRangeSum(vector<int>& nums, int lower, int upper);
bool binarySearch2D(vector<vector<int> >& matrix, int r1, int c1, int r2, int c2, int target);
bool searchMatrix(vector<vector<int> >& matrix, int target);
void addOperatorsDFS(string num, int target, long long diff, long long curNum, string out, vector<string> &res);
vector<string> addOperators(string num, int target);
#endif /* lc_tagDC_h */
