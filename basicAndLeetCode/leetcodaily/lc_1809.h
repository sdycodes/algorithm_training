//
//  lc_1809.hpp
//  FAT
//
//  Created by shidingyuan on 2018/9/16.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#ifndef lc_1809_h
#define lc_1809_h

#include "stdHeader.h"

vector<string> fullJustify(vector<string>& words, int maxWidth);
string simplifyPath(string path);
bool searchExist(int r, int c, vector<vector<char> > board, string word, vector<vector<bool> >& visited);
bool exist(vector<vector<char>>& board, string word);
int removeDuplicates80(vector<int>& nums);
ListNode* deleteDuplicates83(ListNode* head);
ListNode* partition86(ListNode* head, int x);
bool isScramble(string s1, string s2);
bool includeT(int snum[], int tnum[]);
string minWindow(string s, string t);
ListNode* reverseBetween(ListNode* head, int m, int n);
vector<TreeNode*> buildTrees95(int begin, int end);
vector<TreeNode*> generateTrees(int n);
bool isInterleave(string s1, string s2, string s3);
vector<int> twoSum(vector<int>& nums, int target);
ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, int num);
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
int lengthOfLongestSubstring(string s);
#endif /* lc_1809_h */
