//
//  lc_1808.h
//  FAT
//
//  Created by shidingyuan on 2018/8/22.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#ifndef lc_1808_h
#define lc_1808_h

#include "stdHeader.h"
int findContentChildren(vector<int>& g, vector<int>& s);
int jump(vector<int>& nums);
vector<vector<int> > threeSum(vector<int>& nums);
vector<vector<int> > threeSumv2(vector<int>& nums);
int threeSumClosest(vector<int>& nums, int target);
ListNode* reverse1K(ListNode* head, int k);
ListNode* reverseKGroup(ListNode* head, int k);
vector<int> findSubstring(string s, vector<string>& words);
void nextPermutation(vector<int>& nums);
int longestValidParentheses(string s);
int firstMissingPositive(vector<int>& nums);
int trap(vector<int>& height);
void rotate(vector<vector<int>>& matrix);
vector<vector<string>> groupAnagrams(vector<string>& strs);
vector<int> spiralOrder(vector<vector<int>>& matrix);
vector<vector<int> > generateMatrix(int n);
bool canJump(vector<int>& nums);

#endif /* lc_1808_h */
