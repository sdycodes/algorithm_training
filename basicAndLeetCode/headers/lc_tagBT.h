//
//  lc_tagBT.hpp
//  FAT
//
//  Created by shidingyuan on 2018/8/18.
//  Copyright © 2018年 shidingyuan. All rights reserved.
//

#ifndef lc_tagBT_h
#define lc_tagBT_h

#include "stdHeader.h"
vector<string> letterCasePermutation(string S);
vector<string> letterCasePermutation2(string S);
vector<string> calBins(int num, int len);
vector<string> readBinaryWatch(int num);
vector<vector<int>> combine(int n, int k);
vector<string> generateParenthesis(int n, map<int, vector<string> >& memo);
vector<string> wrapGenerateParenthesis(int n);
void backTrace22(vector<string>& res, int left, int right, string cur);
void backTrace39(vector<int> candidates, vector<vector<int> >& res, int target, vector<int> sol, int start);
vector<vector<int>> combinationSum(vector<int>& candidates, int target);
void backTrack40(vector<int> &candidates,int start,int target,vector<int> sol,vector<vector<int>> &res);
vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
void backTrace216(int n, vector<vector<int> >& res, vector<int> sol, int start);
vector<vector<int>> combinationSum3(int k, int n);
bool isParli(string s);
void backtrace131(vector<vector<string> >& res,string s, vector<string> split, int start);
void backtrace90(vector<vector<int> >& res, vector<int> sol, vector<int> nums, int start);
vector<vector<int>> subsetsWithDup(vector<int>& nums);
vector<vector<string> > partition(string s);
void backtrace17(string digits, vector<string>& res, vector<vector<char> > table, string sol, int start);
vector<string> letterCombinations(string digits);
void backtrace93(string s, vector<string>& res, int remain, string cur, int start);
vector<string> restoreIpAddresses(string s);
vector<string> backtrace140(string s, vector<string>& wordDict, map<string, vector<string> >& memo);
vector<string> wordBreak2(string s, vector<string>& wordDict);
bool isMatch(string s, string p);
bool isMatch2(string s, string p);
string backtrace60(vector<int>& nums, int k);
string getPermutation(int n, int k);
bool backtrace37(vector<vector<char> >& board, int r, int c);
void solveSudoku(vector<vector<char>>& board);
bool canbeplace(vector<string> plate, int r, int c);
void backtrace51(vector<vector<string> >& res, int n, int row, vector<string> plate);
vector<vector<string>> solveNQueens(int n);

#endif /* lc_tagBT_h */
